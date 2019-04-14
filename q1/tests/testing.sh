#!/bin/sh

echo `g++ -o solution ../solution.cpp`
echo `g++ -o check check.cpp`

echo "Test set: fail (test should fail)"

i=0
while [ $i -le 4 ]; do
	echo `./check ./fail/${i}`
	i=$(( i + 1 ))
done
echo

echo "Test set: default"
i=0
echo `./check default/${i}`
echo

echo "Test set: random"
i=1
while [ $i -le 1000 ]; do
	echo `./solution < ./random/${i}.in > ./random/${i}.out` | tr '\n' '.'
	echo `./check random/${i}` | tr '\n' '.'
	i=$(( i + 1 ))
done
echo

echo "Test set: repeats"
i=1
while [ $i -le 1000 ]; do
	echo `./solution < ./repeats/${i}.in > ./repeats/${i}.out` | tr '\n' '.'
	echo `./check repeats/${i}` | tr '\n' '.'
	i=$(( i + 1 ))
done
echo

echo "All tests ran"
