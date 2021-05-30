#!/bin/bash

sigint_handler () {
    echo "KILLING SSH"
    kill -s SIGINT $SSH_PID

    echo "KILLING CONTAINER"
    kill -s SIGINT $CONTAINER_PID
}

trap sigint_handler SIGINT

echo "BUILDING IMAGE"
docker build -t dev . > /dev/null

echo "STARTING CONTAINER"
docker run -p 10022:22 --mount type=bind,source="$(pwd)"/../,dst=/home/dev/EzS dev > /dev/null &

CONTAINER_PID=$!

sleep 5

echo "STARTING SSH TUNNEL"
ssh-keygen -f "/home/ezra/.ssh/known_hosts" -R "[localhost]:10022"
sshpass -p "default" ssh -L 5901:127.0.0.1:5901 dev@localhost -p 10022 -o "StrictHostKeyChecking no" -N &
SSH_PID=$!

wait $SSH_PID
wait $CONTAINER_PID
