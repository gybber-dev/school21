#!/bin/bash

MSG='\033[1;33m'
END_MSG='\033[0m'
ERR_MSG='\033[1;31m'
# Sample:
# echo -e "${MSG}sample${END_MSG}"



NGINX_IMG="nginx_img";
WORDPRESS_IMG="wordpress_img"
PHP_IMG="php_img"
SQL_IMG="mysql_img"
CORE_IMG="alpine_nginx"
GRAF_IMG="grafana_img"
INFLUXDB_IMG="influxdb_img"
FTPS_IMG="ftps_img"
TLGRF_IMG="telegraf_img"

minikube delete

# start minikube
echo -e "${MSG}MINIKUBE STARTING...${END_MSG}"
minikube start --vm-driver=none            || echo -e "${ERR_MSG}\t✗${END_MSG}"
eval $(minikube -p minikube docker-env)          || echo -e "${ERR_MSG}\t✗${END_MSG}"

# create images:
echo -e "${MSG}CREATING images${END_MSG}"
docker build . -f core.Dockerfile -t $CORE_IMG
docker build srcs/nginx/. -t $NGINX_IMG          || echo -e "${ERR_MSG}\t✗${END_MSG}"
docker build srcs/wordpress/. -t $WORDPRESS_IMG  || echo -e "${ERR_MSG}\t✗${END_MSG}"
docker build srcs/phpmyadmin/. -t $PHP_IMG       || echo -e "${ERR_MSG}\t✗${END_MSG}"
docker build srcs/mysql/. -t $SQL_IMG            || echo -e "${ERR_MSG}\t✗${END_MSG}"
docker build srcs/grafana/. -t $GRAF_IMG         || docker build srcs/grafana/. -t $GRAF_IMG || echo -e "${ERR_MSG}\t✗${END_MSG}"
docker build srcs/influxdb/. -t $INFLUXDB_IMG    || echo -e "${ERR_MSG}\t✗${END_MSG}"
docker build srcs/telegraf/. -t $TLGRF_IMG       || echo -e "${ERR_MSG}\t✗${END_MSG}"
docker build srcs/ftps/. -t $FTPS_IMG            || echo -e "${ERR_MSG}\t✗${END_MSG}"



## set configs for Kubernetes
echo -e "${MSG}Metal LB enable...${END_MSG}" || echo -e "${ERR_MSG}\t✗${END_MSG}"
minikube addons enable metallb

# update metallb addon
docker pull metallb/speaker:v0.8.2     || echo -e "${ERR_MSG}\t✗${END_MSG}"
docker pull metallb/controller:v0.8.2  || echo -e "${ERR_MSG}\t✗${END_MSG}"

kubectl apply -f srcs/configmap.yaml   || echo -e "${ERR_MSG}\t✗${END_MSG}"

# apply configs:
kubectl create secret generic mysql-pass --from-literal=password=YOUR_PASSWORD || echo -e "${ERR_MSG}\t✗${END_MSG}"
kubectl apply -f srcs/nginx/srcs/nginx.yaml            || echo -e "${ERR_MSG}\t✗${END_MSG}"
kubectl apply -f srcs/wordpress/srcs/wordpress.yaml    || echo -e "${ERR_MSG}\t✗${END_MSG}"
kubectl apply -f srcs/phpmyadmin/srcs/php.yaml         || echo -e "${ERR_MSG}\t✗${END_MSG}"
kubectl apply -f srcs/mysql/srcs/mysql.yaml            || echo -e "${ERR_MSG}\t✗${END_MSG}"
kubectl apply -f srcs/grafana/srcs/grafana.yaml        || echo -e "${ERR_MSG}\t✗${END_MSG}"
kubectl apply -f srcs/influxdb/srcs/influxdb.yaml      || echo -e "${ERR_MSG}\t✗${END_MSG}"
#kubectl apply -f srcs/telegraf/srcs/telegraf.yaml      || echo -e "${ERR_MSG}\t✗${END_MSG}"
kubectl apply -f srcs/ftps/srcs/ftps.yaml              || echo -e "${ERR_MSG}\t✗${END_MSG}"


echo -e "${MSG}Waiting for pods' starting...${END_MSG}"
sleep 2s
kubectl get pods     || echo -e "${ERR_MSG}\t✗${END_MSG}"

#echo -e "${MSG}Starting dashboard${END_MSG}"
#minikube dashboard
