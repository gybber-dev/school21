FROM alpine:3.7

RUN apk update && apk upgrade
RUN apk add nginx supervisor vim