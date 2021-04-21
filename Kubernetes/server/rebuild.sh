#!/bin/bash

DEPLOY_NAME="sql-deploy";
SERVICE_NAME="sql-svc"

eval $(minikube docker-env)

#docker build . -t $NGINX_IMG
#docker build srcs/wordpress/. -t $WORDPRESS_IMG

echo "Deleting nodes:"
kubectl get all
kubectl delete deploy ${DEPLOY_NAME}
kubectl delete svc ${SERVICE_NAME}
#echo "Create nginx pod:"
#kubectl create -f nginx.yml

#kubectl apply -f nginx.yml
#kubectl apply -f srcs/wordpress/srcs/wordpress.yaml

echo "Waiting for pods' starting..."
sleep 2s
kubectl get all
