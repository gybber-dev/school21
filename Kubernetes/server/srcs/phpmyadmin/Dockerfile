FROM alpine:3.7

RUN apk update && apk upgrade
RUN apk add nginx php7 php7-fpm php7-mysqli php7-xml wget supervisor

# optionally:
RUN apk add vim

RUN wget https://www.phpmyadmin.net/downloads/phpMyAdmin-latest-english.tar.gz
RUN tar -xf phpMyAdmin-latest-english.tar.gz  &&  rm -rf phpMyAdmin-latest-english.tar.gz
RUN mv phpMyAdmin-5.1.0-english /var/www/localhost/phpmyadmin


# insert my configs:
COPY srcs/nginx.config /etc/nginx/conf.d/default.conf
COPY srcs/config.inc.php /var/www/localhost/phpmyadmin/config.inc.php
COPY srcs/supervisor.conf /etc/supervisord.conf


# copy scripts:
COPY    srcs/start.sh /tools/start.sh
RUN     chmod +x /tools/start.sh
RUN     mkdir -p /run/nginx

EXPOSE 5000

CMD ["sh", "/tools/start.sh"]
