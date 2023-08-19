#!/bin/bash
for f in 1 2
do
    echo "Current output         Needed output"
    echo "The input is: "
    ./trash.out < "$f.in" > "test_txt.txt"
    cat "$f.in" 
    echo $'\n'
    diff -y -W 50 "test_txt.txt" "$f.out"
    echo $'\n'
done