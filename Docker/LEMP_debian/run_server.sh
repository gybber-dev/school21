service nginx start
#service mysql start
#service php7.3-fpm start

# Configure a wordpress database


ln -s /etc/nginx/sites-available/nginx.config /etc/nginx/sites-enabled/
unlink /etc/nginx/sites-enabled/default
# restore default settings:
# unlink /etc/nginx/sites-enabled/nginx.config
# ln -s /etc/nginx/sites-available/default /etc/nginx/sites-enabled/