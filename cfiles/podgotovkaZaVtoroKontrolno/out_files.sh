#!/bin/bash


if [ $# -ne 2 ]; then
	echo "Not 2 arguments"
	exit 1
fi

dir1=$1;
dir2=$2;

if [ ! -d "$dir" ] || [ ! -d "$dir2" ]; then
	echo "Error"
	exit 1;
fi

coutner1=0;
counter2=0;

counter1=$(find "$dir1" -type f -name "*.out" | wc -l);

counter2=$(find "$dir2" -type f -name "*.out" | wc -l);

if [ $counter1 -gt $counter2 ]; then
	newdir="newDir";
	mkdir "$newdir"
	echo "The name of the new subdirectory is $newdir"
	for file in "$dir1/"; do
		if [ -f "$file" ] && [ -w "$file" ] && [ -r "$file" ]; then
			mv "$file" "$newdir"
		fi
	done
fi
