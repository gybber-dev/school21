FROM	alpine:3.12

#install
EXPOSE	8086
RUN		apk update && apk upgrade && apk add openrc --no-cache supervisor influxdb

RUN		wget https://dl.grafana.com/oss/release/grafana-7.5.4.linux-amd64.tar.gz && tar -zxvf grafana-7.5.4.linux-amd64.tar.gz
RUN 	wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
RUN 	wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.33-r0/glibc-2.33-r0.apk && apk add glibc-2.33-r0.apk

RUN		wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.1_linux_amd64.tar.gz && tar -zxvf telegraf-1.18.1_linux_amd*64.tar.gz

COPY	./srcs/supervisord.conf /etc/supervisord.conf
# COPY	./srcs/telegraf.conf /etc/telegraf.conf
# RUN		sh -c "influxd &" && sleep 4 && echo "CREATE DATABASE telegraf" | influx && echo "CREATE USER admin WITH PASSWORD 'admin' WITH ALL PRIVILEGES" | influx

RUN		mkdir -p /etc/telegraf && ./telegraf-1.18.1/usr/bin/telegraf -sample-config --input-filter docker --output-filter influxdb > /etc/telegraf/telegraf.conf
COPY	./srcs/telegraf.conf /etc/supervisord.conf /etc/telegraf/telegraf.conf

CMD		["/usr/bin/supervisord"]