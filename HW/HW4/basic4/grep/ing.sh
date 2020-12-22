#!/bin/bash

# ing <path to dictionary file>
# prints out words in the dictionary that end with "ing"
# *This must use only one grep command*

# egrep "(ing)$"
if [[ $# -lt 1 ]]; then
    echo "usage: ing <path to dictionary file>"
    exit 1
fi

# TODO
egrep "(ing)$" $1