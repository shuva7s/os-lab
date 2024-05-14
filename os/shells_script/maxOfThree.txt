#!/bin/bash

# Prompt the user to enter three numbers
echo "Enter three numbers separated by spaces:"
read num1 num2 num3

# Check if num1 is greater than or equal to num2 and num3
if [ $num1 -ge $num2 ] && [ $num1 -ge $num3 ]; then
    echo "The maximum of $num1, $num2, and $num3 is: $num1"
# Check if num2 is greater than or equal to num1 and num3
elif [ $num2 -ge $num1 ] && [ $num2 -ge $num3 ]; then
    echo "The maximum of $num1, $num2, and $num3 is: $num2"
# Otherwise, num3 is the maximum
else
    echo "The maximum of $num1, $num2, and $num3 is: $num3"
fi
