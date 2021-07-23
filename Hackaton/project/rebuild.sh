docker build . -t test
docker run -v /Users/yeschall/Desktop/Projects/GitHub/Hackaton/project:/app/local -it --rm test
# docker run -it --rm test