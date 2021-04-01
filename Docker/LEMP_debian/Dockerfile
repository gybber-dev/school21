FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install nginx -y
RUN apt install mariadb-server -y
RUN apt install php-fpm php-mysql -y

# for phpmyadmin
RUN apt-get -y install wget
RUN apt-get -y install php7.3

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz  &&  rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz 					&& 	rm -rf latest.tar.gz

RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Kazan/O=School21/OU=21School/CN=myssl" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt


COPY srcs/nginx.config /etc/nginx/sites-available/
RUN ln -s /etc/nginx/sites-available/nginx.config /etc/nginx/sites-enabled/nginx.config
RUN unlink /etc/nginx/sites-enabled/default

# insert my config

COPY srcs/config.inc.php /phpmyadmin/config.inc.php
COPY srcs/wp-config.php /wordpress/wp-config.php

EXPOSE 80 443

COPY	srcs/start.sh /tools/start.sh
RUN		chmod +x /tools/start.sh
COPY	srcs/toggle_autoindex.sh /tools/toggle_autoindex.sh
RUN		chmod +x /tools/toggle_autoindex.sh
WORKDIR /tools


RUN apt-get -y install vim

CMD bash start.sh
