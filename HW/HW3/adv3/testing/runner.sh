#!/bin/bash

for file in $(ls *test*)
do
    timeout 3 ./$file
    state=$?
    if (( $state == 124 ))
    then
        echo TIMEOUT
    elif (( $state == 1 ))
    then 
        echo FAILTURE
    else 
        echo SUCCESS
    fi
done