#!/bin/bash

# Prompt the user to enter the number of elements in the array
echo "Enter the number of elements in the array:"
read n

# Declare an array
declare -a arr

# Prompt the user to enter the elements of the array
echo "Enter $n elements of the array:"
for (( i=0; i<n; i++ )); do
    read arr[$i]
done

# Calculate the sum of all elements in the array
sum=0
for (( i=0; i<n; i++ )); do
    sum=$((sum + arr[$i]))
done

# Print the sum of all elements in the array
echo "The sum of all elements in the array is: $sum"
