// primes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool is_prime(int);

char key[1024];

int main(int argc, char* argv[])
{
	for (int i = 0; i < 100; i++) {
		if (is_prime(i)) {
			printf("%d ", i);
		}
	}

	printf("Press a key to continue.");
	scanf_s("%s", key);
	return 0;
}

bool is_prime(int n)
{
	return n % 2 == 0;
}