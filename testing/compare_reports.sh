#!/bin/bash

grep Failed $1 | awk '{print $3}' | grep -o -E '[0-9]+' | sort -n > fail1

grep Failed $2 | awk '{print $3}' | grep -o -E '[0-9]+' | sort -n > fail2

diff fail1 fail2 > result

cat result

rm fail1 fail2
