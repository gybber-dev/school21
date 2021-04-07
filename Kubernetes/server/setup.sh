#!/bin/bash

NGINX_IMG="nginx_img";


minikube start --vm-driver=virtualbox
eval $(minikube -p minikube docker-env)

docker build . -t $NGINX_IMG

#optionally:
sleep 5s
minikube dashboard