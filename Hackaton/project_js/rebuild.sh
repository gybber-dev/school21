docker build . -t test
docker run -v /Users/yeschall/Desktop/Projects/GitHub/Hackaton/project_js:/app/local -it --rm test
# docker run -it --rm test