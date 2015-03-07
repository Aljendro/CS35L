#!/bin/bash
MAX=100000
count=0

while [ $count -le $MAX ] ; do
    random=$RANDOM
    let "random = ($random % 30)"
    openssl rand -base64 $random >> tempFile.txt
    let "count = ($count + 1)"
done
