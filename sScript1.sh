#!/bin/bash
while true
do
echo "1.Read only permission files"
echo "2.File with formatted output"
echo "3.Replacing current date with '**'"
echo "4.Changing case"
echo "5.Exit"
echo "Enter your choice"
read ch
if [ $ch == 1 ]
then
  echo "Number of files having read only command"
  ls -l|grep r--r--r-- -c
elif [ $ch == 2 ]
then
  cat count.sh
elif [ $ch == 3 ]
then
  echo "File created today"
  read f_name
  set -- `ls -l $f_name`
  if [ -f "$f_name" ]
  then
    ncal -h|grep $7|sed "s|$7|"**"|"
  else
    echo File not found
  fi
elif [ $ch == 4 ]
then
  echo "Enter the filename"
  read new_file
   if [ -f "$new_file" ]
   then
     echo "File name to be stored in"
     read new_file1
     cat $new_file|head -3|tr '[a-z]' '[A-Z]' > $new_file1
     cat $new_file1
   else
     echo File not found
   fi
else
 exit
fi
done
