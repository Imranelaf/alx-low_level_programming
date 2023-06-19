#!/bin/bash
gcc -Wall -Werror -Wextra -pedantic -c *.c
gcc -shared -fPIC -o liball.so *.c
