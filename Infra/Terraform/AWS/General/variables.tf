variable "instance_name" {
  description = "Name of the instance"
  type        = string
  default     = "learn-terraform-aws-instance"
}

variable "instance_type" {
  description = "Type of the instance"
  type        = string
  default     = "t3.micro"
}
