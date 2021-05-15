#!/bin/sh

echo "grafana is starting..."
#ln -s /grafana-7.5.5/bin/grafana-server /grafana-server
./bin/grafana-server && kill -s SIGTERM $(cat supervisord.pid)
#/usr/bin/supervisord -c /etc/supervisord.conf || echo "error"
sh