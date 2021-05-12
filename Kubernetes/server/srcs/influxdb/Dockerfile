FROM alpine:3.12

# optionally:
RUN		apk update && apk upgrade && apk add openrc --no-cache supervisor influxdb
# RUN apk add influxdb --repository=http://dl-cdn.alpinelinux.org/alpine/v3.10/community/

# because telegraf not found
RUN wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
RUN wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.33-r0/glibc-2.33-r0.apk && apk add glibc-2.33-r0.apk

# install telegraf:
RUN		wget https://dl.influxdata.com/telegraf/releases/telegraf-1.18.2_linux_amd64.tar.gz && tar -zxvf telegraf-1.18.2_linux_amd64.tar.gz

# copy scripts:
RUN		mkdir -p /etc/telegraf && ./telegraf-1.18.2/usr/bin/telegraf -sample-config --input-filter docker --output-filter influxdb > /etc/telegraf/telegraf.conf

# insert my configs:
COPY srcs/supervisord.conf /etc/supervisord.conf
COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf
EXPOSE 8086

CMD		["/usr/bin/supervisord"]
