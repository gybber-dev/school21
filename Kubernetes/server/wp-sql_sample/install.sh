#!/bin/bash
##
# Example from the documentation:
# https://kubernetes.io/docs/tutorials/stateful-application/mysql-wordpress-persistent-volume/
##

#run minikube:

bash ../setup.sh

curl -LO https://k8s.io/examples/application/wordpress/mysql-deployment.yaml
curl -LO https://k8s.io/examples/application/wordpress/wordpress-deployment.yaml

sleep 1s
kubectl apply -k ./

sleep 2s
echo "Creating a secret:"
kubectl create secret generic mysql-pass --from-literal=password=YOUR_PASSWORD
kubectl get secrets
kubectl get pods

echo "Creating service's url"
minikube service wordpress --url
echo "..copy it to the browser"
