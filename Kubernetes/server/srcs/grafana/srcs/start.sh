#!/bin/sh

echo "grafana is starting..."
#ln -s /grafana-7.5.5/bin/grafana-server /grafana-server
/usr/bin/supervisord -c /etc/supervisord.conf || echo "error"
sh
echo "buy..."