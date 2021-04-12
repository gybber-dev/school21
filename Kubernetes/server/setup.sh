#!/bin/bash

MSG='\033[1;33m'
END_MSG='\033[0m'
# Sample:
# echo -e "${MSG}sample${END_MSG}"



NGINX_IMG="nginx_img";
WORDPRESS_IMG="wordpress_img"

# start minikube
echo -e "${MSG}MINIKUBE STARTING...${END_MSG}"
minikube start --vm-driver=virtualbox
eval $(minikube -p minikube docker-env)

# create images:
echo -e "${MSG}CREATING images${END_MSG}"
docker build srcs/nginx/. -t $NGINX_IMG
docker build srcs/wordpress/. -t $WORDPRESS_IMG



## set configs for Kubernetes
echo -e "${MSG}Metal LB enable...${END_MSG}"
minikube addons enable metallb
kubectl apply -f srcs/configmap.yaml




# apply configs:
kubectl apply -f srcs/nginx/srcs/nginx.yaml
#kubectl apply -f srcs/nginx/srcs/wordpress.yaml

echo -e "${MSG}Waiting for pods' starting...${END_MSG}"
sleep 2s
kubectl get pods

#optionally:
sleep 5s
minikube dashboard