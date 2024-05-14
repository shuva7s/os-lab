#!/bin/bash

# Prompt the user to enter the number of terms
echo "Enter the number of terms for Fibonacci series:"
read num_terms

# Initialize the first two Fibonacci numbers
a=0
b=1
echo "Fibonacci series up to $num_terms terms starting from the third term:"

# Generate the Fibonacci numbers starting from the third term using a for loop
for (( i=3; i<=num_terms; i++ )); do
    next=$((a + b))
    echo -n "$next "
    a=$b
    b=$next
done

echo
