#!/bin/bash

set -e

echo "🚀 Starting Spark deployment on Minikube..."

# Check if minikube is running
if ! minikube status | grep -q "Running"; then
    echo "Starting Minikube cluster..."
    minikube start
fi

# Build the Spark Docker image
echo "🔨 Building Spark Docker image..."
eval $(minikube docker-env)
docker build -t spark-image:latest .

# Apply Terraform configuration
echo "🏗️  Applying Terraform configuration..."
terraform init
terraform apply -auto-approve

# Wait for namespace to be created
echo "⏳ Waiting for namespace to be created..."
kubectl wait --for=condition=Active namespace/spark --timeout=60s

# Apply Kubernetes manifests
echo "📦 Applying Kubernetes manifests..."
kubectl apply -f k8s/

# Wait for deployments to be ready
echo "⏳ Waiting for Spark Master to be ready..."
kubectl wait --for=condition=available --timeout=300s deployment/spark-master -n spark

echo "⏳ Waiting for Spark Workers to be ready..."
kubectl wait --for=condition=available --timeout=300s deployment/spark-worker -n spark

echo "⏳ Waiting for Spark History Server to be ready..."
kubectl wait --for=condition=available --timeout=300s deployment/spark-history-server -n spark

# Get service URLs
echo "🌐 Getting service URLs..."
SPARK_MASTER_URL=$(minikube service spark-master -n spark --url | head -1)
SPARK_WEBUI_URL=$(minikube service spark-master -n spark --url | tail -1)
HISTORY_SERVER_URL=$(minikube service spark-history-server -n spark --url)

echo "✅ Spark deployment completed!"
echo ""
echo "📊 Service URLs:"
echo "  Spark Master: $SPARK_MASTER_URL"
echo "  Spark Web UI: $SPARK_WEBUI_URL"
echo "  History Server: $HISTORY_SERVER_URL"
echo ""
echo "�� Useful commands:"
echo "  kubectl get pods -n spark"
echo "  kubectl logs -f deployment/spark-master -n spark"
echo "  kubectl logs -f deployment/spark-worker -n spark"
echo "  minikube dashboard"
echo ""
echo "�� To clean up:"
echo "  terraform destroy -auto-approve"
echo "  minikube stop" 