#!/bin/bash
if [ -z $1 ] || [ -z $2 ]; then
        echo "Two arguments are required\n first argument is directory path to be searched\n second argument is text string to be searched in first argument path\n"
        exit 1
fi

filesdir=$1
searchstr=$2
y=$(grep -rn $searchstr $filesdir | wc -l)
x=$(grep -rn $searchstr $filesdir | uniq -c | wc -l)
echo "The number of files are $x and the number of matching lines are $y"