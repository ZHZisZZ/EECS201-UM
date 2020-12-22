#!/bin/bash

# same-lower-vowel <path to dictionary file>
# print out words in the dictionary that contain at least 2 of the same lowercase vowel *in a row*
# (for the sake of this assignment: a,e,i,o,u are vowels, and y is never a vowel)
# e.g. aardvark, week, radii, zoom, vacuum
# *This must use only one grep command*
# Hint: think about backreferences


if [[ $# -lt 1 ]]; then
    echo "usage: same-lower-vowel <path to dictionary file>"
    exit 1
fi

egrep "([aeiou])\1" $1
