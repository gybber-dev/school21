#!/bin/bash

docker build . -t sample
docker run -it --rm sample