#!/bin/sh

echo "SQL's nginx is starting..."
rc default
/etc/init.d/mariadb setup
rc-service mariadb start

PASSWDDB=$WORDPRESS_DB_PASSWORD
MAINDB='wordpress'
USER='admin'
mysql -e "CREATE DATABASE ${MAINDB}"
mysql -e "CREATE USER ${USER}@'%' IDENTIFIED BY '${PASSWDDB}';"
mysql -e "GRANT ALL PRIVILEGES ON ${MAINDB}.* TO '${USER}'@'%';"
mysql -e "FLUSH PRIVILEGES;"

mysql wordpress < /tools/wordpress.sql

/usr/bin/supervisord -c /etc/supervisord.conf