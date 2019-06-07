#!/bin/bash
while true
do

 echo "1.Count number of files with read only permissions"
 echo "2.Display formatted output of a file"
 echo "3.Change in case of file content"
 echo "4.Replacement of date with '**'"
 echo "5.Exit"
 echo "Enter your choice"
 read ch
 case $ch in
  1) echo "Count of files with read only permission"
     ls -l|grep r--r--r-- -c ;;
  2) echo "Enter the file name"
     read f_name
     set -- ` ls -l $f_name`
     if [ -f "$f_name" ]
     then
	echo File name $9
	echo Time $8
	echo Date $7
	echo Month $6
	echo Size $5
	echo Group $4
	echo User $3
	echo File or Directory $2
	echo Permissions $1
     else
	echo File not found
     fi ;;
  3) echo "Enter the file name that contains the text"
     read fn
      if [ -f "$fn" ]
      then
	echo "Enter the file name to store the text"
	read new_file
	cat $fn|head -4|tr '[a-z]' '[A-Z]'>$new_file
	cat $new_file
      else
	echo "File not found"
      fi ;;
  4) echo "Enter the file name created today"
     read fdate
     set -- ` ls -l $fdate`
      if  [ -f "$fdate" ]
      then
	ncal -h|grep $7|sed "s| $7|**|"
      else
	echo "Not possible"
      fi ;;
   5) exit ;;
   *) echo Invalid choice ;;
  esac
done
