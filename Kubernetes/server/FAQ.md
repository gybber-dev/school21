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

#### Как запустить терминал в поде?

Через dashboard зайти на стринциу Пода и нажать на кнопку "Exec into Pod"

#### Как запустить 2 процесса в одном поде?

Отключить supervisor. Подробнее в видео ~1:40:00

#### Как создать пароль для входа в wordpress

Для конфиг файла из [документации](https://raw.githubusercontent.com/kubernetes/website/master/content/en/examples/application/wordpress/mysql-deployment.yaml)
выполнить:

````
kubectl create secret generic mysql-pass --from-literal=password=YOUR_PASSWORD
````

#### Как перезапустить nginx в Alpine:

````
nginx -s reload
````

#### Не открывается сервис, переходя по ссылке пода в dashboard'e по протоколу http, если установлен порт 80

Установил другие значения портов для каждого сервиса


#### При переходе в папку wordpress скачивается файл, но не открывается

Не срабатывает php, необходимо установить все расширения. Возможно, список необходимых расширений будет указан в логе 
web-сервера. См. логи nginx.

#### Что такое редирект

#### Как скопировать файл из контейнера пода в хост?

kubectl cp -h           =>      установить tar в контейнер
kubectl cp default/grafana-deploy-7856d949bd-2sfw4:/etc/telegraf/telegraf.conf telegraf.conf

kubectl cp  <namespace>/<pod>:<src path> <dst path>
(kubectl get namespaces)
````
kubectl cp default/influxdb-deploy-77ccc594d8-jmq48:/etc/telegraf/telegraf.conf telegraf.conf
````

#### Установка и настройка telegraf:
https://vk.com/@swquinc-chast-monitoring-kubernetes-influxdb-telegraf-grafana
https://octoperf.com/blog/2019/09/19/kraken-kubernetes-influxdb-grafana-telegraf/#prerequisites

#### Установка пакетов alpine из сторонних репозиториев
https://pkgs.org/




### TO DO:

Попробовать запустить самый простой index.php в wordpress'e

config
persistantVolume
