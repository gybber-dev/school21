#!/bin/bash


#YAML_FILE="mysql/srcs/mysql.yaml"
#IMG_NAME="";

#IMG_NAME="wordpress_img";
#YAML_FILE="wordpress/srcs/wordpress.yaml"

#IMG_NAME="grafana/. -t grafana_img";
#YAML_FILE="grafana/srcs/grafana.yaml"

IMG_NAME="influxdb/. -t influxdb_img";
YAML_FILE="influxdb/srcs/influxdb.yaml"

#IMG_NAME="telegraf/. -t telegraf_img";
#YAML_FILE="telegraf/srcs/telegraf.yaml"
#DEPLOY_NAME="ftps-deploy";
#SERVICE_NAME="ftps-svc"
#IMG_NAME="ftps_img";
#YAML_FILE="ftps/srcs/ftps.yaml"

eval $(minikube docker-env)

#docker build . -t $NGINX_IMG
docker build srcs/$IMG_NAME
kubectl delete -f srcs/${YAML_FILE}
kubectl apply -f srcs/${YAML_FILE}
#kubectl apply -R -f  srcs/telegraf/srcs/examples/.

sleep 2s
kubectl get all
