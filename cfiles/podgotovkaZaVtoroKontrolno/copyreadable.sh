#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Not 1 parameter"
	exit 1;
fi

string=$1;

counter1=0;

if [ ! -d "$string" ]; then
	mkdir "$string"
fi

for files in *; do 
	if [ -f "$files" ]; then
		if [ -r "$files" ]; then
			cp "$files" "$string/"
		else 
			((counter1++))
		fi
	fi
done

echo "The number ot the other files is: $counter1"


