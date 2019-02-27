echo Enter the file name
read f_name
if [ -f "$f_name" ]
then
 set -- `ls -l $f_name`
 echo Name of the file $9
 echo Time of creation is $8
 echo Date creation $7
 echo Month creation $6
 echo Size $5
 echo Group $4
 echo User $3
 echo Directory or File $2
 echo File permission $1
else
 echo File not found
fi
