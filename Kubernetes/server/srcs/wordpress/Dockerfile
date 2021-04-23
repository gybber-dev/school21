FROM alpine_nginx

# optionally:
RUN apk add wget php7 php7-fpm

RUN     apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli

# RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Kazan/O=School21/OU=21School/CN=wp-ssl" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt

# RUN  ln -s /wordpress /var/www/localhost/wordpress
RUN     mkdir /tools
COPY    srcs/start.sh /tools/start.sh
RUN     chmod +x /tools/start.sh
RUN     mkdir -p /run/nginx


WORKDIR /var/www/localhost

# install wordpress
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz    &&    rm -rf latest.tar.gz

# insert my configs:
COPY srcs/nginx.config /etc/nginx/conf.d/default.conf
COPY srcs/wp-config.php ./wordpress/wp-config.php
COPY srcs/supervisor.conf /etc/supervisord.conf


EXPOSE 5050

CMD ["sh", "/tools/start.sh"]
# CMD ["nginx", "-g", "daemon off;"]