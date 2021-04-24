#!/bin/bash

#DEPLOY_NAME="sql-deploy";
#SERVICE_NAME="sql-svc";
#IMG_NAME="";
DEPLOY_NAME="wordpress";
SERVICE_NAME="wordpress-svc"
IMG_NAME="wordpress_img";

eval $(minikube docker-env)

#docker build . -t $NGINX_IMG
docker build srcs/wordpress/. -t $IMG_NAME

echo "Deleting nodes:"
kubectl get all
kubectl delete deploy ${DEPLOY_NAME}
kubectl delete svc ${SERVICE_NAME}
#echo "Create nginx pod:"
#kubectl create -f nginx.yml

#kubectl apply -f nginx.yml
kubectl apply -f srcs/wordpress/srcs/wordpress.yaml

echo "Waiting for pods' starting..."
sleep 2s
kubectl get all
