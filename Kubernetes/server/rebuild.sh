#!/bin/bash

#DEPLOY_NAME="sql-deploy";
#SERVICE_NAME="sql-svc";
#YAML_FILE="mysql/srcs/mysql.yaml"
#IMG_NAME="";
DEPLOY_NAME="wordpress";
SERVICE_NAME="wordpress-svc"
IMG_NAME="wordpress_img";
YAML_FILE="wordpress/srcs/wordpress.yaml"
#DEPLOY_NAME="grafana-deploy";
#SERVICE_NAME="grafana-svc"
#IMG_NAME="grafana_img";
#YAML_FILE="grafana/srcs/grafana.yaml"
#DEPLOY_NAME="influxdb-deploy";
#SERVICE_NAME="influxdb-svc"
#IMG_NAME="influxdb_img";
#YAML_FILE="influxdb/srcs/influxdb.yaml"

#DEPLOY_NAME="ftps-deploy";
#SERVICE_NAME="ftps-svc"
#IMG_NAME="ftps_img";
#YAML_FILE="ftps/srcs/ftps.yaml"

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
kubectl apply -f srcs/${YAML_FILE}

echo "Waiting for pods' starting..."
sleep 2s
kubectl get all
