output "vpc_id" {
  description = "The ID of the VPC"
  value       = module.vpc.vpc_id
}

output "public_subnets" {
  description = "List of public subnet IDs"
  value       = module.vpc.public_subnets
}

output "default_security_group_id" {
  description = "Default security group Id"
  value = module.vpc.default_security_group_id
}