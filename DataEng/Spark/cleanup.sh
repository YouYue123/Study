#!/bin/bash

echo "🧹 Cleaning up Spark deployment..."

# Delete Kubernetes resources
kubectl delete -f k8s/ --ignore-not-found=true

# Destroy Terraform resources
terraform destroy -auto-approve

# Stop minikube
minikube stop

echo "✅ Cleanup completed!" 