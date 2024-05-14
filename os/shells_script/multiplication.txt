#!/bin/bash

# Prompt the user to enter the first number
echo "Enter the first number:"
read num1

# Prompt the user to enter the second number
echo "Enter the second number:"
read num2

# Perform the multiplication
result=$((num1 * num2))

# Display the result
echo "The result of multiplication is: $result"
