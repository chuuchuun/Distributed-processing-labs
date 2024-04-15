#include <stdio.h>
#include "factorial.h"
#include "fibonacci.h"
#include "isPrime.h"
#include "power.h"
#include "exponential.h"
#include "gcd.h"
#include "lcm.h"
#include "isValidTriangle.h"
int main() {
	printf("The factorial is :%d\n", factorial(2));
	printf("The sizth element of Fibonacci sequence is: %d\n", fibonacci(6));
	printf("This number is prime: %d\n", isPrime(13));
	printf("3 to 4 power is :%d \n", power(3, 4));

	printf("Rounded down exponential is: \n", exponential(0));
	printf("GCD for 6 and 24 is: %d\n", gcd(6, 24));
	printf("LCM for 13 and 39 is: %d\n", lcm(13, 39));
	printf("The triangle is valid: %d\n", isValidTriangle(3, 4, 5));
	return 0;
}