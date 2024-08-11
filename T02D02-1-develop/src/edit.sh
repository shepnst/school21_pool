#!/bin/bash
FILE_PATH=$1
string=$2
replace=$3
cd ..
if [ "$#" -lt 3 ]; then
	echo "you entered wrong number of arguments"
	exit 1
fi
if [ ! -f $FILE_PATH ]; then
    echo "the path doesnt exist"
    exit 1
fi

if [ "$?" -eq 0 ]; then
    if grep -q $string $FILE_PATH; then
        sed -i '' -e "s/$string/$replace/g" $FILE_PATH
        path=$FILE_PATH
        date=$(stat -f "%Sm" -t"%Y-%m-%d %H:%M" $FILE_PATH)
        size=$(stat -f%z $FILE_PATH)
        sha=$(shasum -a 256 $FILE_PATH | cut -d' ' -f1)
        log_message=$path" - "$size" - "$date" - "$sha" - ""shasum -a 256"
        echo $log_message >> src/files.log
    else
        echo "this substring doesnt exist in the file"
    fi
fi

#you may test the script using in terminal: sh edit.sh test/test.txt A B
