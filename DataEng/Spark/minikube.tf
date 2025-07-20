terraform {
  required_providers {
    minikube = {
      source = "scott-the-programmer/minikube"
      version = ">= 0.5.2"
    }
    kubernetes = {
      source  = "hashicorp/kubernetes"
      version = ">= 2.25.0"
    }
    kubectl = {
      source  = "gavinbunney/kubectl"
      version = ">= 1.14.0"
    }
  }
}

provider "minikube" {}

provider "kubernetes" {
  config_path = "~/.kube/config"
}

provider "kubectl" {
  config_path = "~/.kube/config"
}

# Create Minikube cluster with enhanced configuration
resource "minikube_cluster" "spark_cluster" {
  cluster_name = "spark-minikube"
  driver       = "docker"
  cpus         = 6
  memory       = "12288mb"
  disk_size    = "20g"
  
  addons = [
    "dashboard",
    "default-storageclass",
    "storage-provisioner",
    "ingress",
    "metrics-server"
  ]
  # Configure container runtime
  container_runtime = "containerd"
  
  # Configure Kubernetes version
  kubernetes_version = "v1.28.0"
}

# Create namespace for Spark
resource "kubernetes_namespace" "spark_namespace" {
  depends_on = [minikube_cluster.spark_cluster]
  
  metadata {
    name = "spark"
    labels = {
      name = "spark"
    }
  }
}

# Create ConfigMap for Spark configuration
resource "kubernetes_config_map" "spark_config" {
  depends_on = [kubernetes_namespace.spark_namespace]
  
  metadata {
    name      = "spark-config"
    namespace = kubernetes_namespace.spark_namespace.metadata[0].name
  }

  data = {
    "spark-defaults.conf" = file("${path.module}/conf/spark-defaults.conf")
    "log4j.properties"    = file("${path.module}/conf/log4j.properties")
  }
}

# Create PersistentVolumeClaim for Spark logs
resource "kubernetes_persistent_volume_claim" "spark_logs_pvc" {
  depends_on = [kubernetes_namespace.spark_namespace]
  
  metadata {
    name      = "spark-logs-pvc"
    namespace = kubernetes_namespace.spark_namespace.metadata[0].name
  }

  spec {
    access_modes = ["ReadWriteOnce"]
    resources {
      requests = {
        storage = "10Gi"
      }
    }
    storage_class_name = "standard"
  }
}

# Create ServiceAccount for Spark
resource "kubernetes_service_account" "spark_service_account" {
  depends_on = [kubernetes_namespace.spark_namespace]
  
  metadata {
    name      = "spark-service-account"
    namespace = kubernetes_namespace.spark_namespace.metadata[0].name
  }
}

# Create ClusterRoleBinding for Spark
resource "kubernetes_cluster_role_binding" "spark_cluster_role_binding" {
  depends_on = [kubernetes_namespace.spark_namespace]
  
  metadata {
    name = "spark-cluster-role-binding"
  }

  role_ref {
    api_group = "rbac.authorization.k8s.io"
    kind      = "ClusterRole"
    name      = "edit"
  }

  subject {
    kind      = "ServiceAccount"
    name      = kubernetes_service_account.spark_service_account.metadata[0].name
    namespace = kubernetes_namespace.spark_namespace.metadata[0].name
  }
}

# Output cluster info
output "minikube_cluster_info" {
  value = {
    cluster_name = minikube_cluster.spark_cluster.cluster_name
    status       = minikube_cluster.spark_cluster.status
    kubeconfig   = minikube_cluster.spark_cluster.kubeconfig
  }
}

output "spark_namespace" {
  value = kubernetes_namespace.spark_namespace.metadata[0].name
}