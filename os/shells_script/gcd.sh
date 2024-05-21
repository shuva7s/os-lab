#!/bin/bash

# Function to find the GCD of two numbers
gcd() {
    local num1=$1
    local num2=$2

    while [ $num2 -ne 0 ]; do
        remainder=$((num1 % num2))
        num1=$num2
        num2=$remainder
    done

    echo "The GCD of $1 and $2 is: $num1"
}

# Prompt the user to enter two numbers
echo "Enter two numbers separated by space:"
read num1 num2

# Call the function to find the GCD
gcd $num1 $num2
