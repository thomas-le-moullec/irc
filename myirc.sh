#!/bin/sh

PORT=$1
AV="$#"
ID_RANDOM="$$"
LOGDIR="./.logs/"
USER="$USER"
NUM_TEST="0"
LOCALHOST="127.0.0.1"

function initialise_ta {
    if [ $AV -ne 1 ]; then
	echo "Usage: $0 [PORT]"
	exit
    fi
    echo "Hello $USER, waiting for the opening of the server on port $PORT..."
    sleep 1
    mkdir $LOGDIR > /dev/null 2>&1
    echo "We have created a '.logs' directory"
    sleep 1
}

function close_ta {
    echo "Waiting to close server ..."
    sleep 1
    killall server > /dev/null 2>&1
}

function launch_server {
    if [ ! -f ./server ]; then
	echo "server executable not found!"
	exit
    fi
    ./server $PORT & > /dev/null 2>&1
    if [ `ps | grep server | wc -l` -gt 0 ]; then
	echo "The server was successfully launched on $PORT' port !"
    else
	echo "Lauching of the server on $PORT' port failed !"
	exit
    fi
    sleep 1
}

function execute {
    echo "Waiting for the Execution of $1 Test ('$2')"
    sleep 1
    (echo -ne $2) | nc $LOCALHOST $PORT | cat -e > $LOGDIR"test$NUM_TEST.$PORT"
    let "NUM_TEST=NUM_TEST+1"
    sleep 1
}

initialise_ta
launch_server
echo
echo "------------- BASICS TEST------------------"
echo
execute "Simple Authentification" "NICK toto\nUSER toto\nQUIT\n"
execute "Simple Authentification" "QUIT\n"
close_ta
