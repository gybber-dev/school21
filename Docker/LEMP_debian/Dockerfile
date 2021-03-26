FROM debian:buster

# install nginx:
RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get install nginx -y
# RUN apt install mariadb-server -y
# RUN apt install php-fpm php-mysql -y


COPY nginx.config /etc/nginx/sites-available/
EXPOSE 80


