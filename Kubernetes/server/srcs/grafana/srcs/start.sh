#!/bin/sh

echo "grafana is starting..."
./bin/grafana-server && kill -s SIGTERM $(cat supervisord.pid)
