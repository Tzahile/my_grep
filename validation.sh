#!/usr/bin/env bash

./compile.sh
cat emptyTest | ./ex2 | diff empty_grep -
cat oneLine | ./ex2 | diff oneLineOut
