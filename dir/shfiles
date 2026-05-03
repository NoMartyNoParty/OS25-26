#!/bin/bash


read -p "Directory name: " string;
read -p "Enter comparable size: " number;

if [ -d "$string" ]; then
	find "$string" -type f | while read file; do 	
		currentsize=$(wc -c < "$file")
		if [ $currentsize -gt $number ]; then 
	 		echo "Files: $file\n";
        	fi
	done
fi
