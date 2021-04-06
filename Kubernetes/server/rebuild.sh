#!/bin/bash

kubectl get pods
kubectl delete pods --all
kubectl create -f nginx.yml
kubectl apply -f nginx.yml
kubectl get pods
