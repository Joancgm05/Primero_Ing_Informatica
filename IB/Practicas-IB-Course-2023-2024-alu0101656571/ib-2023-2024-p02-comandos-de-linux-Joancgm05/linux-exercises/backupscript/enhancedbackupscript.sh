#!/bin/bash
echo "Backing up files (not directories) in home-directory"
cd
echo "Home directory:"
pwd
destination=/tmp/homebackup_$(date +%Y-%m-%d)
echo "target directory:"
mkdir $destination
echo "copying to $destination"
cp -p -u *.* $destination
echo "done"
