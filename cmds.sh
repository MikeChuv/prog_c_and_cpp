#!/bin/bash

function cpplab() {
	labname=$1
	mkdir $labname
	cd $labname
	cp -i /home/mike/Docs/prog_c_and_cpp/start.sh /home/mike/Docs/prog_c_and_cpp/$labname/
	touch main.cpp
	touch README.md
	echo Created files for $labname
}

