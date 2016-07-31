if [ "$#" -ne 2 ]; then
    echo "Usage : ./perf.sh <binary path> <maze path>"
    exit 1
fi

filename="$1"
maze="$2"

time ./"$filename" "$maze"
