#!/bin/bash

n=$1

if [[ $n -gt 0 ]]
then 
  echo "The number is positive"
elif [[ $n -lt 0 ]]
then 
  echo "The number is negative"
else
  echo "The number is zero"
fi

