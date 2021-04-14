#!/bin/bash

NGINX_IMG="nginx_img";
WORDPRESS_IMG="wordpress_img"

eval $(minikube -p minikube docker-env)

#docker build . -t $NGINX_IMG
docker build srcs/wordpress/. -t $WORDPRESS_IMG

echo "Deleting nodes:"
kubectl get all
kubectl delete deploy wordpress-deploy
kubectl delete svc wordpress-svc
#echo "Create nginx pod:"
#kubectl create -f nginx.yml

kubectl apply -f nginx.yml
kubectl apply -f srcs/wordpress/srcs/wordpress.yaml

echo "Waiting for pods' starting..."
sleep 2s
kubectl get all
