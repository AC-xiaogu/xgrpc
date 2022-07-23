#!/bin/bash

set -e

if [ ! -d build ];then
  mkdir build
fi

rm -rf `pwd`/build/*
cd `pwd`/build &&
	cmake .. &&
	make
cd ..
