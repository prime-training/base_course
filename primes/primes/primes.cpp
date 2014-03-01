// primes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

bool is_prime(int);

char key[1024];

int main(int argc, char* argv[])
{
	for (int i = 0; i < 100; i++) {
		if (is_prime(i)) {
			printf("%d ", i);
		}
	}

	printf("Press Enter to continue\n");
	getchar();
	return 0;
}

bool is_prime(int n)
{
	for (int i = 2; i < n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}