#!/bin/bash

docker build -t dev .
docker run -p 10022:22 --mount type=bind,source="$(pwd)"/../,dst=/home/dev/EzS dev &
sleep 5
ssh -L 5901:127.0.0.1:5901 dev@localhost -p 10022 -N

