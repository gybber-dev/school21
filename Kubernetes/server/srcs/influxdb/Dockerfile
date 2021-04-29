FROM alpine_nginx

# optionally:
RUN apk add mysql mysql-client openrc

# insert my configs:
COPY srcs/supervisor.conf /etc/supervisord.conf


# copy scripts:
RUN     cp /etc/mysql/my.cnf /etc/mysql/my.cnf.orig
COPY    srcs/start.sh /tools/
COPY    srcs/my.cnf /etc/mysql/
COPY    srcs/wordpress.sql /tools
RUN     chmod +x /tools/start.sh

EXPOSE 3306

CMD ["sh", "/tools/start.sh"]
