#!/bin/bash

read -p "First file: " first;
read -p "Second file: " second;

mv "$first" "tempfile"
mv "$second" "$first"
mv "tempfile" "$first"
