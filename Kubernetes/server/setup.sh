#!/bin/bash

MY_MSG='\033[1;33m'
NORMAL='\033[0m'
# Sample:
# echo -e "${MY_MSG}sample${NORMAL}"



NGINX_IMG="nginx_img";

# start minikube
echo -e "${MY_MSG}MINIKUBE STARTING...${NORMAL}"
minikube start --vm-driver=virtualbox
eval $(minikube -p minikube docker-env)

# create images:
echo -e "${MY_MSG}CREATING images${NORMAL}"
docker build . -t $NGINX_IMG

# set configs for Kubernetes
echo -e "${MY_MSG}MetalLB enable...${NORMAL}"
minikube addons enable metallb


# apply configs:
kubectl apply -f nginx.yml
echo -e "${MY_MSG}Waiting for pods' starting...${NORMAL}"
sleep 2s
kubectl get pods

#optionally:
sleep 5s
minikube dashboard