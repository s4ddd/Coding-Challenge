#!/bin/sh

echo `g++ -o solution ../solution.cpp`

i=0
f=0
while [ $i -le 1599 ]; do
	if [ $i -eq 500 ]; then
		f=500
	elif [ $i -eq 1000 ]; then
		f=1000
	elif [ $i -eq 1500 ]; then
		f=1500
	fi

	echo `./solution < ./other/${f}/${i}.in > temp.out` | tr -d '\n'
	echo `diff ./other/${f}/${i}.out temp.out` | tr -d '\n'

	i=$(( i + 1 ))
done
echo

echo "All tests ran"