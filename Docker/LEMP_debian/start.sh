#!bin/bash

service nginx start
service php7.3-fpm start
service mysql start

# Configure a wordpress database
echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password
echo "update mysql.user set plugin='' where user='root';"| mysql -u root --skip-password

cp -fr /wordpress /var/www/html/
cp -fr /phpmyadmin /var/www/html/


echo $1



if [ $1 = "off" ];  then
  echo "here"
  sed -i "17 s/autoindex on;/autoindex off;/" /etc/nginx/sites-available/nginx.config
fi
#if [ $1 = AUTOINDEX=on ];  then
#   	sed -i "17 s/autoindex off;/autoindex on;/" /etc/nginx/sites-available/nginx.config
#fi

# sleep 100000000000

bash