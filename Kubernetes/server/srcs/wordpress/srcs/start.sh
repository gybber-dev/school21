#!/bin/sh

echo "wordpress nginx is starting..."
#0_nginx -g 'daemon off;'
#php-fpm7 -F
/usr/bin/supervisord -c /etc/supervisord.conf
