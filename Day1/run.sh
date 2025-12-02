#!/bin/sh

rm -rf ./bin

find * -name "*.java" > sources.txt

javac -d bin @sources.txt

java -cp bin srcs.main.me.rcortesb.aocDay1.Main