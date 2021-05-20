FROM alpine_nginx

# optionally:
RUN apk add wget


RUN wget https://dl.grafana.com/enterprise/release/grafana-enterprise-7.5.5.linux-amd64.tar.gz
RUN tar -zxvf grafana-enterprise-7.5.5.linux-amd64.tar.gz  &&  rm grafana-enterprise-7.5.5.linux-amd64.tar.gz

RUN wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
RUN wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.33-r0/glibc-2.33-r0.apk && apk add glibc-2.33-r0.apk

# insert my configs:
COPY srcs/grafana.db /grafana-7.5.5/data/grafana.db
RUN  chmod +x /grafana-7.5.5/data/grafana.db

# copy scripts:
COPY    srcs/start.sh /tools/start.sh
RUN     chmod +x /tools/start.sh
RUN     mkdir -p /run/nginx
WORKDIR grafana-7.5.5

EXPOSE 3000

CMD ["sh", "/tools/start.sh"]
