# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vblood <vblood@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/26 17:39:22 by vblood            #+#    #+#              #
#    Updated: 2021/01/28 18:10:57 by vblood           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt-get update -y
RUN apt-get upgrade -y

# Установка Nginx / Openssl / Mariadb-server(MYSQL) / Php-mysql(fpm)(mbstring) / Wget #

RUN apt-get install -y nginx
RUN apt-get install -y openssl
RUN apt-get install -y mariadb-server
RUN apt-get install -y php-mysql
RUN apt-get install -y php-fpm
RUN apt-get install -y php-mbstring
RUN apt-get install -y wget


COPY ./srcs/init.sh .
COPY ./srcs/default ./etc/nginx/sites-available/
COPY ./srcs/autoindex.sh ./etc/nginx/sites-available/

# Установка PhpMyAdmin #
WORKDIR /var/www/html
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.3/phpMyAdmin-5.0.3-english.tar.gz
RUN tar -xvzf phpMyAdmin-5.0.3-english.tar.gz && rm -rf phpMyAdmin-5.0.3-english.tar.gz
RUN mv phpMyAdmin-5.0.3-english phpMyAdmin

# Установка WordPress #
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz

COPY ./srcs/wp-config.php ./wordpress
COPY ./srcs/config.inc.php ./phpMyAdmin

# Установка SSL Certificate #
RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=RT/L=Kazan/O=Kazan/OU=21kazan/CN=vblood" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt

RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*

WORKDIR /../../../../


EXPOSE 80 443
CMD bash init.sh

# docker build -t test . 
# docker run -it --rm -p 80:80 -p 443:443 test
# docker rmi $(docker images -a -q) -f
# apt-get install vim - установка Vim
# docker exec -it "container name" bash
# docker run -d --rm -p 80:80 -p 443:443 test