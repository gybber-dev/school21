#!/bin/bash

imageName=ft_server
containerName=ft_server

docker build . --tag $imageName

echo Run new container...
docker run -it --rm -p 80:80 $containerName