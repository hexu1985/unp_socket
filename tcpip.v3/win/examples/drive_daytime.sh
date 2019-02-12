#!/usr/bin/env bash

SRV_PORT=$(($RANDOM + 1024))
./daytimed $SRV_PORT &
SRV_PID=$!
sleep 1
./TCPdaytime 127.0.0.1 $SRV_PORT
./UDPecho 127.0.0.1 $SRV_PORT <<EOF
what's the time?
EOF

sleep 1
kill $SRV_PID
