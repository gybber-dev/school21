FROM alpine:3.7

RUN apk update && apk upgrade
RUN apk add nginx mysql mysql-client

# optionally:
RUN apk add vim

# insert my configs:
COPY srcs/nginx.config /etc/nginx/conf.d/default.conf
COPY srcs/config.inc.php /var/www/localhost/phpmyadmin/config.inc.php
COPY srcs/supervisor.conf /etc/supervisord.conf


# copy scripts:
COPY    srcs/start.sh /tools/start.sh
RUN     chmod +x /tools/start.sh
RUN     mkdir -p /run/nginx

EXPOSE 3306

CMD ["sh", "/tools/start.sh"]
