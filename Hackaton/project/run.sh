# docker exec -it $(docker ps -q) bash -c "python -u runner.py"
docker exec -it $(docker ps -q)  bash -c "cd local; python -u runner.py"