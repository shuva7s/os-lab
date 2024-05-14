#!/bin/bash

# Declare an array to store the numbers
declare -a arr

# Prompt the user to enter 10 numbers
echo "Enter 10 numbers: "
for (( i=0; i<10; i++ )); do
    read num
    arr[$i]=$num
done

# Prompt the user to enter the key number to search for
echo "Enter the key number to search for:"
read key

# Perform linear search
found=false
for (( i=0; i<10; i++ )); do
    if [ "${arr[i]}" -eq $key ]; then
        found=true
        break
    fi
done

# Display the result
if [ $found = true ]; then
    echo "The key number $key was found in the array."
else
    echo "The key number $key was not found in the array."
fi
