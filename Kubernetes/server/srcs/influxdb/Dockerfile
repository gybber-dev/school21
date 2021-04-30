FROM alpine_nginx

# optionally:
RUN apk add openrc
RUN apk add influxdb --repository=http://dl-cdn.alpinelinux.org/alpine/v3.10/community/

# insert my configs:
# COPY srcs/supervisor.conf /etc/supervisord.conf

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz && rm telegraf-1.18.2_linux_amd64.tar.gz


# copy scripts:
# RUN     cp /etc/mysql/my.cnf /etc/mysql/my.cnf.orig
COPY    srcs/start.sh /tools/
# COPY    srcs/my.cnf /etc/mysql/
# COPY    srcs/wordpress.sql /tools
RUN     chmod +x /tools/start.sh

EXPOSE 8086

CMD ["sh", "/tools/start.sh"]
