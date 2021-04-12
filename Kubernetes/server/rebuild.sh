#!/bin/bash

NGINX_IMG="nginx_img";

eval $(minikube -p minikube docker-env)
docker build . -t $NGINX_IMG
echo "Deleting nodes:"
kubectl get all
kubectl delete deploy --all
kubectl delete svc --all
#echo "Create nginx pod:"
#kubectl create -f nginx.yml
kubectl apply -f nginx.yml
echo "Waiting for pods' starting..."
sleep 2s
kubectl get all
