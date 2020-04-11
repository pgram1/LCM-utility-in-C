#!/usr/bin/env bash

# TODO: add parameters to lcm.c
# if [[ $# -lt 2 ]]; then
#     printf "%s\n" "Syntax: lcm.sh number_2 number_2"
#     exit 1
# fi

gcc lcm.c -o lcm.out
./lcm.out
exit 0