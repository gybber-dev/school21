FROM debian:buster

RUN apt update
RUN apt -y upgrade
RUN apt -y install nginx
RUN apt -y install mariadb-server
RUN apt -y install php7.3 php-fpm php-mysql php-xml
RUN apt -y install wget

RUN wget https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-english.tar.gz
RUN tar -xf phpMyAdmin-latest-english.tar.gz  &&  rm -rf phpMyAdmin-latest-english.tar.gz
RUN mv phpMyAdmin-5.1.0-english phpmyadmin

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz 					&& 	rm -rf latest.tar.gz

RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Kazan/O=School21/OU=21School/CN=myssl" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt

# insert my configs:

COPY srcs/config.inc.php /phpmyadmin/config.inc.php
COPY srcs/wp-config.php /wordpress/wp-config.php
COPY srcs/nginx.config /etc/nginx/sites-available/
RUN ln -s /etc/nginx/sites-available/nginx.config /etc/nginx/sites-enabled/nginx.config
RUN unlink /etc/nginx/sites-enabled/default

# copy scripts:

COPY	srcs/start.sh /tools/start.sh
COPY	srcs/toggle_autoindex.sh /tools/toggle_autoindex.sh
RUN		chmod +x /tools/start.sh
RUN		chmod +x /tools/toggle_autoindex.sh
WORKDIR /tools

RUN apt -y install vim

EXPOSE 80 443

CMD bash start.sh
