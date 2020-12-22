#!/bin/bash

# needs at least one argument
# sed -e "s@// \(.*\)@/* \1 */@"

if [[ $# -lt 1 ]]; then
    echo "usage: c89ify.sh <C files>"
    echo "  Turns C99/C++ style // coments into /* */ comments."
    echo "  Produces a file that has \".c89\" inserted before the \".c\" extension for each provided file"
    echo "  For example: \"c89ify.sh hello.c world.c\" will produce \"hello.c89.c\" and \"world.c89.c\" files"
    exit 1
fi

sed -e "s@// \(.*\)@/* \1 */@" $1 > $(echo $1 | sed -e "s@.c@.c89.c@")