FROM debian:buster

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install nginx -y
RUN apt install mariadb-server -y
RUN apt install php-fpm php-mysql -y

# for phpmyadmin
RUN apt-get -y install wget


RUN apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz

RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Kazan/O=School21/OU=21School/CN=myssl" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt


COPY nginx.config /etc/nginx/sites-available/
RUN ln -s /etc/nginx/sites-available/nginx.config /etc/nginx/sites-enabled/nginx.config
RUN unlink /etc/nginx/sites-enabled/default


# insert my config
WORKDIR /var/www/html
COPY config.inc.php /phpmyadmin/config.inc.php
COPY wp-config.php /wordpress/wp-config.php

# ENV AUTOINDEX on
RUN chown -R www-data:www-data *

WORKDIR /

COPY start.sh /start.sh
RUN chmod +x /start.sh
CMD bash /start.sh
