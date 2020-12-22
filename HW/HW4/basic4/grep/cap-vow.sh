#!/bin/bash

# cap-vow <path to dictionary file>
# print out words in the dictionary that start with a capital vowel
# (for the sake of this assignment: a,e,i,o,u are vowels, and y is never a vowel)
# *This must use only one grep command*


# grep "^[aeiou].*" 
if [[ $# -lt 1 ]]; then
    echo "usage: cap-vow <path to dictionary file>"
    exit 1
fi

# TODO
egrep "^[AEIOU]" $1