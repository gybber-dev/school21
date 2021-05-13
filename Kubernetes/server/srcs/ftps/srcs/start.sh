#!/bin/sh

echo "ftps is starting..."

/usr/bin/supervisord -c /etc/supervisord.conf
