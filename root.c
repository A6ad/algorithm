#include <stdio.h>

// Function to calculate the square root using the Newton-Raphson method
double squareRoot(double n) {
    double x = n;
    double y = 1.0;
    double e = 0.000001; // Precision level

    while (x - y > e) 
    {
        x = (x + y) / 2;    
        y = n / x;
    }
    return x;
}

int main() {
    double num;
    printf("Enter any positive number: ");
    scanf("%lf", &num);  // Read the input number
    if (num < 0) {
        printf("Invalid input. Please enter a positive number.\n");
        return 1;
    }
    double result = squareRoot(num);  // Calculate the square root
    printf("Square root is: %.6lf\n", result);  // Print the result
    return 0;
}