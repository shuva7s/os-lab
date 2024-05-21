#!/bin/bash

# Define the calculator function
calculator() {
    # Prompt user for two numbers
    read -p "Enter first number: " num1
    read -p "Enter second number: " num2

    # Display menu
    echo "Calculator Menu:"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Exit"

    # Prompt user for choice
    read -p "Enter your choice (1-5): " choice

    # Perform operations based on user choice
    case $choice in
        1)  # Addition
            result=$((num1 + num2))
            echo "Result: $result"
            ;;
        2)  # Subtraction
            result=$((num1 - num2))
            echo "Result: $result"
            ;;
        3)  # Multiplication
            result=$((num1 * num2))
            echo "Result: $result"
            ;;
        4)  # Division
            if [ $num2 -eq 0 ]; then
                echo "Error: Division by zero!"
            else
                result=$(echo "scale=2; $num1 / $num2" | bc)
                echo "Result: $result"
            fi
            ;;
        5)  # Exit
            echo "Exiting calculator."
            exit 0
            ;;
        *)  # Invalid choice
            echo "Invalid choice. Please enter a number from 1 to 5."
            ;;
    esac
}

# Call the calculator function
calculator
