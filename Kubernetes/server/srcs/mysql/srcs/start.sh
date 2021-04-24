#!/bin/sh

echo "SQL's nginx is starting..."

PASSWDDB='1234'
MAINDB='wordpress'
rc default
/etc/init.d/mariadb setup
rc-service mariadb start

mysql -e "CREATE DATABASE ${MAINDB}"
mysql -e "CREATE USER ${MAINDB}@'%' IDENTIFIED BY '${PASSWDDB}';"
mysql -e "GRANT ALL PRIVILEGES ON ${MAINDB}.* TO '${MAINDB}'@'%';"
mysql -e "FLUSH PRIVILEGES;"

/usr/bin/supervisord -c /etc/supervisord.conf

if [ $? -eq 1 ]
then
  echo "Could run the script" >&2
  exit 1;
fi