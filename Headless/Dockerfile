FROM ubuntu:18.04
RUN apt update && apt install -y vim curl sudo iputils-ping
RUN sudo apt-get install -y nodejs
RUN apt-get install -y npm
RUN npm install puppeteer
RUN node node_modules/puppeteer/install.js
COPY example.js .
CMD bash