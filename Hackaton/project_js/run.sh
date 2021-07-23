# docker exec -it $(docker ps -q) bash -c "python -u runner.py"
docker exec -it $(docker ps -q)  bash -c "cd local; node index"

# docker exec -it 630b2fe38a91 bash