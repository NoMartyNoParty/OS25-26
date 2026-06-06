#!/bin/bash

if [ $# -ne 1 ]; then
	echo "Not 1 arguments"
	exit 1
fi

if [ ! $1 -d ]; then
	echo "Not a directory"
	exit 1
fi

dir=$1;

read -p "Enter an existing file: " $file;

head -2 "$file" > tempfile;

for files in "$dir/"; do 
	if [ "$files" -f ]; then
		(cat tempfile; tail -n +3 "$files") > temp1 && mv temp1 "$files";
	fi
done

rm tempfile;
