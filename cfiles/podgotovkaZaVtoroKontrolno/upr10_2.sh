#!/bin/bash

if [ $# -lt 3 ]; then
	echo "Less than 3 arguments"
	exit 1;
fi

num=$1;
dir=$2;
users=$3;

if [ ! dir -d ]; then
	read " $dir is not a directory"
	exit 1;
fi

read -p "Enter some text: " $text;

coutner=0;

for usernames in "$@"; do
	if who | grep -q "$username"; then
		usersub="$dir/$username";
		if [ usersub -d ]; then
			count=$(find "$usersub" -type f | wc -l);
			if [ $count -gt $num ]; then
				echo "$text" | write "$username"
			else 
				echo "Username: $username, Files: $count" > temp
			fi
		fi
	fi
done

if [ -s "$temp" ]; then
	sort "$temp" > "results.txt"
fi

rm "$temp"
