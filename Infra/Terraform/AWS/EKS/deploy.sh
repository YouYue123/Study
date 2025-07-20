#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

echo -e "${GREEN}🚀 Starting EKS Sample App Deployment${NC}"

# Check if kubectl is installed
if ! command -v kubectl &> /dev/null; then
    echo -e "${RED}❌ kubectl is not installed. Please install kubectl first.${NC}"
    exit 1
fi

# Check if Docker is installed
if ! command -v docker &> /dev/null; then
    echo -e "${RED}❌ Docker is not installed. Please install Docker first.${NC}"
    exit 1
fi

# Build Docker image
echo -e "${YELLOW}📦 Building Docker image...${NC}"
cd app
docker build -t sample-app:latest .
if [ $? -ne 0 ]; then
    echo -e "${RED}❌ Docker build failed${NC}"
    exit 1
fi
cd ..

# Load image to kind (if using kind) or push to registry
# For this example, we'll assume you're using a local registry or kind
echo -e "${YELLOW}📤 Loading image to cluster...${NC}"

# Apply Kubernetes manifests
echo -e "${YELLOW}🔧 Applying Kubernetes manifests...${NC}"

# Create namespace
kubectl apply -f k8s/namespace.yaml

# Apply ConfigMap
kubectl apply -f k8s/configmap.yaml

# Apply Deployment
kubectl apply -f k8s/deployment.yaml

# Apply Service
kubectl apply -f k8s/service.yaml

# Apply Ingress (optional - requires ALB controller)
kubectl apply -f k8s/ingress.yaml

# Apply HPA
kubectl apply -f k8s/hpa.yaml

# Wait for deployment to be ready
echo -e "${YELLOW}⏳ Waiting for deployment to be ready...${NC}"
kubectl wait --for=condition=available --timeout=300s deployment/sample-app -n sample-app

# Get service information
echo -e "${GREEN}✅ Deployment completed!${NC}"
echo -e "${YELLOW}📋 Service Information:${NC}"
kubectl get svc -n sample-app

echo -e "${YELLOW}�� Pod Information:${NC}"
kubectl get pods -n sample-app

echo -e "${YELLOW}📋 Ingress Information:${NC}"
kubectl get ingress -n sample-app

echo -e "${GREEN}🎉 Sample app deployed successfully!${NC}"
echo -e "${YELLOW}�� To access the app:${NC}"
echo -e "   - Port forward: kubectl port-forward svc/sample-app-service 8080:80 -n sample-app"
echo -e "   - Then visit: http://localhost:8080" 