#!/bin/bash
echo "Backing up files (not directories) in home-directory"
cd
echo "Home directory:"
pwd
echo "target directory:"
mkdir /tmp/homebackup
echo "copying to /tmp/homebackup"
cp -p -u *.* /tmp/homebackup
echo "done"
