#!/bin/sh

echo "ftps is starting..."
adduser -D alex
echo "alex:alex" | chpasswd
mkdir /home/alex/ftp
chown nobody:nogroup /home/alex/ftp
chmod a-w /home/alex/ftp
mkdir /home/alex/ftp/files
chown alex:alex /home/alex/ftp/files
echo "vsftpd sample file" > /home/alex/ftp/files/sample.txt

echo "running ftp server..."
vsftpd etc/vsftpd/vsftpd.conf
