FROM alpine_nginx

# optionally:
RUN apk add openssl

RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Kazan/O=School21/OU=21School/CN=myssl" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt

# insert my configs:
COPY srcs/nginx.config /etc/nginx/conf.d/default.conf

# copy scripts:
COPY    srcs/start.sh /tools/start.sh
RUN     chmod +x /tools/start.sh
RUN     mkdir -p /run/nginx

WORKDIR /tools

EXPOSE 80 443

CMD ["sh", "start.sh"]
