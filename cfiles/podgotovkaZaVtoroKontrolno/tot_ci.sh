#!/bin/bash

if [ $# -ne 2 ]; then
	echo "Not 2 parameters"
	exit 1; 
fi

dir1=$1;
dir2=$2;

if [ ! -d "$dir1" ] || [ ! -d "$dir2" ]; then
	echo "Error with the directories"
	exit 1;
fi

counter1=0;
counter2=0;

counter1=$(find "$dir1" -type f -name "*.c" | wc -l);
counter2=$(find "$dir2" -type f -name "*.c" | wc -l);

if [ $(($counter1 + $counter2)) -gt 20 ]; then
	newfile="results.txt";

	find "$dir1" -type f -name "*.c" | ls > newfile;
	find "$dir2" -type f -name "*.c" | ls > newfile;

	chmod +r "$newfile"
else 
	echo "The number of these C-files is: $(($counter1 + $counter2))"
fi
