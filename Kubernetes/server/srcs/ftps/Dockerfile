FROM alpine:3.12

# optionally:
RUN apk add vim supervisor wget vsftpd openrc vsftpd-doc


# insert my configs:
COPY srcs/supervisor.conf /etc/supervisord.conf


# copy scripts:
COPY    srcs/start.sh /tools/start.sh
RUN     chmod +x /tools/start.sh
RUN     mkdir -p /run/nginx
RUN     rc-update add vsftpd default
# RUN     rc-service vsftpd start

EXPOSE 21

CMD ["sh", "/tools/start.sh"]
