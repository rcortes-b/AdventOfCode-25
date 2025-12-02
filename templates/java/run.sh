#!/bin/sh

rm -rf ./bin

find * -name "*.java" > sources.txt

javac -d bin @sources.txt

## Modify the package dat --> e.g aocDay1
java -cp bin srcs.main.me.rcortesb.<modify_here>.Main