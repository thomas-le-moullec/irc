#!/bin/sh

AV="$#"
PORT=$1

PORT_EPI="6667"
LOCALHOST="127.0.0.1"
IP_EPI="irc.epitech.eu"

LOGDIR="./.logs/"
USER="$USER"
NUM_TEST="0"
OUT_USER=outStudent
OUT_EPI=outEpi

TAIL=`which tail`
MKFIFO=`which mkfifo`
MKDIR=`which mkdir`
CP=`which cp`
KILLALL=`which killall`
PIPE_EPI=pipeStudent
PIPE_USER=pipeEpi

USER_IRC="./server.$$"

function initialise_ta {
    if [ ! -f ./server ]; then
	echo "server executable not found!"
	exit
    fi
    if [ $AV -ne 1 ]; then
	echo "Usage: $0 [PORT]"
	exit
    fi
    $CP ./server $USER_IRC
    echo "Hello $USER, waiting for the opening of the server on port $PORT..."
    sleep 1
    $MKDIR -p $LOGDIR > /dev/null 2>&1
    rm -f $LOGDIR* > /dev/null 2>&1
    echo "We have created a '.logs' directory"
    sleep 0.1
}

function cleanUser {
    rm -f $PIPE_USER $OUT_USER mytail 2>&1 > /dev/null
}

function cleanEpitech {
    rm -f $PIPE_EPI $OUT_EPI epitechTail 2>&1 > /dev/null
}

function kill_user_server {
    if [ `pidof $USER_IRC | wc -l` -ne 0 ]
    then
        $KILLALL -9 $USER_IRC 2>&1 > /dev/null
    fi
    if [ `pidof mytail | wc -l` -ne 0 ]
    then
	$KILLALL mytail 2>&1 > /dev/null
    fi
    sleep 0.2
    cleanUser
}

function kill_epitech_client {
    if [ `pidof nc | wc -l` -ne 0 ]
    then
        $KILLALL -9 $nc 2>&1 > /dev/null
    fi
    if [ `pidof epitechTail | wc -l` -ne 0 ]
    then
	$KILLALL epitechTail 2>&1 > /dev/null
    fi
    sleep 0.2
    cleanEpitech
}

function launch_user_server {
    $USER_IRC $PORT & > /dev/null 2>&1
    if [ `pidof $USER_IRC | wc -l` -ne 0 ]
    then
	echo "The server was successfully launched on $PORT' port !"
    else
	echo "Lauching of the server on $PORT' port failed !"
	exit
    fi
    sleep 0.3
}

function launch_user_client {
    $MKFIFO $PIPE_USER
    cp $TAIL mytail 2>&1 >/dev/null
    (./mytail -f $PIPE_USER 2>/dev/null | nc $LOCALHOST $PORT | cat -e > $OUT_USER 2>&1 &) >/dev/null 2>/dev/null
}

function launch_epitech_client {
    $MKFIFO $PIPE_EPI
    cp $TAIL epitechTail 2>&1 >/dev/null
    (./mytail -f $PIPE_EPI 2>/dev/null | nc $IP_EPI $PORT_EPI | cat -e > $OUT_EPI 2>&1 &) >/dev/null 2>/dev/null
}

function connect_to_epitech_irc {
    echo "Waiting to Connect to Epitech' IRC..."
    sleep 0.3
    (echo -ne "USER $USER 0 * :$USER\nNICK $USER\n") | nc $IP_EPI $PORT_EPI
}

function execute_diff {
    echo "Execution of $1 Test ('$2')"
    kill_user_server
    kill_epitech_client
    launch_user_server
    launch_user_client $2
    if [ `pidof $USER_IRC | wc -l` -eq 1 ]
    then
	echo $2 > $PIPE_USER
	echo "USER:"
	cat $OUT_USER
    fi
    sleep 0.5
    launch_epitech_client $2
    if [ `pidof epitechTail | wc -l` -eq 1 ]
    then
	echo "EPITECH:"
	echo $2 > $PIPE_EPI
	cat $OUT_EPI
    fi
    sleep 0.3
#    (echo -ne $2) | nc $LOCALHOST $PORT | cat -e > $LOGDIR"test$NUM_TEST.$PORT"
    let "NUM_TEST=NUM_TEST+1"
}

function finish_ta {
    echo "TA finished, Cleaning Directory ..."
    sleep 1
    kill_user_server
    kill_epitech_client
    rm -f $USER_IRC
}

initialise_ta
echo
echo "------------- BASICS TEST------------------"
echo
execute_diff "Simple Authentification" "NICK toto\nUSER toto\nQUIT\n"
finish_ta
