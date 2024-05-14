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

# Sort the array in descending order
sorted_arr=($(printf '%s\n' "${arr[@]}" | sort -nr))

# Print the third largest number
if [ ${#sorted_arr[@]} -ge 3 ]; then
    echo "The third largest number in the array is: ${sorted_arr[2]}"
else
    echo "Error: Array has less than three elements."
fi
