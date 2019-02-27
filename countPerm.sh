#!/bin/bash
echo "Count of files having read only commond"
ls -l|grep r--r--r-- -c


