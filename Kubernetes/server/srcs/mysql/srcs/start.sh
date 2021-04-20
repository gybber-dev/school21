#!/bin/sh

echo "SQL's nginx is starting..."

/usr/bin/supervisord -c /etc/supervisord.conf

if [ $? -eq 1 ]
then
  echo "Could run the script" >&2
  exit 1;
fi