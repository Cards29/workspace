#!/bin/bash

echo "Enter a number: "
read n

if [ $n -le 1 ] 
then
  echo "Number is not prime"
  exit 0
fi

i=2
while [ $((i * i)) -le $n ]
do 
  r=$((n % i))

  if [ $r -eq 0 ]
  then
    echo "Number is not prime"
    exit 1
  fi

  i=$((i + 1))
done

echo "Number is prime"
