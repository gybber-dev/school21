FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get -y install wget

RUN apt-get -y install nginx

# copy config file to image
WORKDIR /var/www/html
COPY nginx.config .
COPY run_server.sh .


RUN apt-get -y install mariadb-server

RUN bash run_server.sh
