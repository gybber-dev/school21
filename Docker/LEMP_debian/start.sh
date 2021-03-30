#!/bin/bash

service nginx start
service php7.3-fpm start
service mysql start

# Configure a wordpress database
echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password



ln -s /wordpress /var/www/html/wordpress
ln -s /phpmyadmin /var/www/html/phpmyadmin


echo $1



if [[ $1 == "off" ]];  then
  sed -i "17 s/autoindex on;/autoindex off;/" /etc/nginx/sites-available/nginx.config
  echo "autoindex is off..."
else
  echo "autoindex is on..."
fi
#if [ $1 = AUTOINDEX=on ];  then
#   	sed -i "17 s/autoindex off;/autoindex on;/" /etc/nginx/sites-available/nginx.config
#fi

service nginx restart
# sleep 100000000000
bash