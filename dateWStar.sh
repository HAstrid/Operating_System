#!/bin/bash
echo Replacing current date with "**"
echo Enter the file name created today
read f_name
set -- `ls -l $f_name`
ncal -h|grep $7|sed "s|$7|"**"|"
