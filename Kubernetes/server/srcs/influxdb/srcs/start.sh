#!/bin/sh

echo "influxdb is starting..."
#cd /influxdb
influxd
#PASSWDDB='1234'
#MAINDB='wordpress'
#USER='admin'
#rc default
#/etc/init.d/mariadb setup
#rc-service mariadb start
#
#mysql -e "CREATE DATABASE ${MAINDB}"
#mysql -e "CREATE USER ${USER}@'%' IDENTIFIED BY '${PASSWDDB}';"
#mysql -e "GRANT ALL PRIVILEGES ON ${MAINDB}.* TO '${USER}'@'%';"
#mysql -e "FLUSH PRIVILEGES;"
#
#
#mysql wordpress < /tools/wordpress.sql
#
#/usr/bin/supervisord -c /etc/supervisord.conf
#
#if [ $? -eq 1 ]
#then
#  echo "Could run the script" >&2
#  exit 1;
#fi