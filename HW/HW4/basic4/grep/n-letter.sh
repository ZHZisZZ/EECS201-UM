#!/bin/bash

# n-letter <path to dictionary file> <n>
# print out words in the dictionary that are composed of only n alphabetic letters; no apostrophes or other punctuation
# *This must use only one grep command*

# egrep "^[[:alpha:]]{n}$"
if [[ $# -lt 2 ]]; then
    echo "usage: n-letter <path to dictionary file> <n>"
    exit 1
fi

# TODO
egrep "^[[:alpha:]]{$2}$" $1 
