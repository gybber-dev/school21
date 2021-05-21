FROM alpine_nginx

# optionally:
RUN apk add wget php7 php7-fpm

RUN     apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-json

RUN     mkdir /tools
RUN     mkdir -p /run/nginx

WORKDIR /var/www/localhost

# install wordpress
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz    &&    rm -rf latest.tar.gz

# insert my configs:
COPY srcs/nginx.config /etc/nginx/conf.d/default.conf
COPY srcs/wp-config.php ./wordpress/wp-config.php
COPY srcs/supervisor.conf /etc/supervisord.conf
COPY srcs/themes /var/www/localhost/wordpress/wp-content/themes

EXPOSE 5050
CMD ["/usr/bin/supervisord", "-c", "/etc/supervisord.conf"]