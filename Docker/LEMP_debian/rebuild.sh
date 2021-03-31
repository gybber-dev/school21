#!/bin/bash

docker image rm -f $(docker images -q)
docker build . -t ft_server
docker run -itp 80:80 -p 443:443 --rm ft_server