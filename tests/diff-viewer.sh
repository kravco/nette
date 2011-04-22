#!/bin/sh

if test $# -gt 3; then
	echo "Usage: $0 [ <num = 1> [ <binary = meld> [ <log = diff.log> ] ] ]"
	echo "  (invokes <diff executable> <actual> <expected>)"
	exit 1
fi

num=$1; bin=$2; log=$3

if test $# -lt 3; then
	log=diff.log
	if test $# -lt 2; then
		bin=meld
		if test $# -lt 1; then
			num=1
		fi
	fi
fi

# saves the path to this script's directory
dir=` dirname $0 `

# absolutizes the path if necessary
if echo $dir | grep -v ^/ > /dev/null; then
	dir=` pwd `/$dir
fi

# find test log entry
line=` grep "^$num " "$dir/$log" `

if test -z "$line"; then
	echo "Test #$num is not present in diff log '$log'."
	exit 1
fi

line=` echo $line | cut -d ' ' -f 3- `

# runs diff viewer
$bin $line

# returns what script returned
