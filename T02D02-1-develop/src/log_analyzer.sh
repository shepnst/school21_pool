FILE_PATH=$1
cd ..
if [ "$#" -ne 1 ]; then
    echo "you entered wrong number of arguments"
    exit 1
fi

if [ ! -f $FILE_PATH ]; then
    echo "the path doesnt exist"
    exit 1
fi

if [ "${FILE_PATH##*.}" != "log" ]; then
    echo "the extension is wrong, try again"
    exit 1
fi
    

if [ "$?" -eq 0 ]; then
    first=$(grep -c $ $FILE_PATH)

    second=$(awk -F'-' '{print $1}' $1 | sort -u | grep -c "/")

    echo $first $second $((first-1))
fi
