FROM alpine_nginx

# optionally:
RUN apk add openrc tar
RUN apk add influxdb --repository=http://dl-cdn.alpinelinux.org/alpine/v3.10/community/

# insert my configs:
COPY srcs/supervisor.conf /etc/supervisord.conf

# install telegraf:
RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz
RUN tar xf telegraf-1.18.2_linux_amd64.tar.gz && rm telegraf-1.18.2_linux_amd64.tar.gz
RUN cat
RUN mv /telegraf-1.18.2 /telegraf

# copy scripts:
RUN     cp -fR /telegraf/etc/telegraf/ /etc/telegraf

COPY    srcs/start.sh /tools/
COPY    srcs/telegraf.conf /etc/telegraf/telegraf.conf
# COPY    srcs/my.cnf /etc/mysql/
# COPY    srcs/wordpress.sql /tools
RUN     chmod +x /tools/start.sh

EXPOSE 8086

CMD ["sh", "/tools/start.sh"]
