FROM alpine:3.12

# optionally:
RUN apk add vim supervisor wget vsftpd openrc vsftpd-doc openssl
RUN openssl req -x509 -nodes -days 365 -subj "/C=RU/ST=Russia/L=Kazan/O=School21/OU=21School/CN=myssl" -newkey rsa:2048 -keyout /etc/ssl/vsftpd.key -out /etc/ssl/vsftpd.crt


# insert my configs:
RUN     mv /etc/vsftpd/vsftpd.conf /etc/vsftpd/vsftpd.conf.backup
COPY    srcs/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY    srcs/vsftpd.userlist /etc/vsftpd/vsftpd.userlist

# copy scripts:
COPY    srcs/start.sh /tools/start.sh
RUN     chmod +x /tools/start.sh

EXPOSE 21 30021

CMD ["sh", "/tools/start.sh"]
