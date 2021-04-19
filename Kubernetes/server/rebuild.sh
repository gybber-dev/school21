#!/bin/bash

NGINX_IMG="nginx_img";
WORDPRESS_IMG="wordpress_img"

¡

#docker build . -t $NGINX_IMG
docker build srcs/wordpress/. -t $WORDPRESS_IMG

echo "Deleting nodes:"
kubectl get all
kubectl delete deploy wordpress
kubectl delete svc wordpress-svc
#echo "Create 0_nginx pod:"
#kubectl create -f 0_nginx.yml

kubectl apply -f nginx.yml
kubectl apply -f srcs/wordpress/srcs/wordpress.yaml

echo "Waiting for pods' starting..."
sleep 2s
kubectl get all
