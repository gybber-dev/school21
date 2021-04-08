#### Почему не стоит запускать Kubernetes не на виртаульной машине? 

Kubernetes требователен к ОС, в которой запускается - необходим Linux. Чтобы запустить Kubernetes на хосте необходимо 
явно прописать флаг

````bash
--vm-driver=none
````

Подробнее на [оф. сайте](https://kubernetes.io/ru/docs/setup/learning-environment/minikube/#%D1%83%D0%BA%D0%B0%D0%B7%D0%B0%D0%BD%D0%B8%D0%B5-%D0%B4%D1%80%D0%B0%D0%B9%D0%B2%D0%B5%D1%80%D0%B0-%D0%B2%D0%B8%D1%80%D1%82%D1%83%D0%B0%D0%BB%D1%8C%D0%BD%D0%BE%D0%B9-%D0%BC%D0%B0%D1%88%D0%B8%D0%BD%D1%8B)

#### Как сделать образы Docker'a видимыми для Kubernetes?

Необходимо выполнить команду:

````
eval $(minikube -p minikube docker-env)
````

#### Что такое services в чем отличие от Deployment?

[Source](https://kubernetes.io/docs/concepts/services-networking/service/#motivation)
[читай](https://matthewpalmer.net/kubernetes-app-developer/articles/service-kubernetes-example-tutorial.html#:~:text=What's%20the%20difference%20between%20a,to%20a%20set%20of%20pods.&text=Then%20our%20service%20could%20route,them%20based%20on%20their%20labels.)
Deployment - для стабилизации работы подов. Services - для сетевой навигации по подам.

[Про Services](https://kubernetes.io/ru/docs/tutorials/kubernetes-basics/expose/expose-intro/)
[Habr](https://habr.com/ru/company/ruvds/blog/438984/)

#### Как поставить под на прослушивание?

````
kubectl port-forward nginx-svc 8080:80
````
[Habr](https://habr.com/ru/company/ruvds/blog/438984/)


#### Как обратиться к сервису?

````
minikube service sa-frontend-lb
````



### TO DO:

Добавить файл-конфигурацию для metalLB
Добавить файл-конфигурацию для Deployment