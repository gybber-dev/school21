FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get -y install wget

RUN apt-get -y install nginx

# copy config file to image
WORKDIR /var/www/html
COPY nginx.config .

RUN apt-get -y install mariadb-server
