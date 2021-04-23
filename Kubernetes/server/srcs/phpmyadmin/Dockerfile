FROM alpine_nginx

# optionally:
RUN apk add wget php7 php7-fpm php7-mysqli php7-xml php7-iconv php7-json php7-zlib php7-curl php7-mbstring php7-session


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
