#!/bin/bash

read -p "Enter active user: " user;

while ! who | grep -wq "$user"; do
	sleep 5
done

echo "========================"
echo "User '$user' just landed in!"
echo "Stop cheking"
