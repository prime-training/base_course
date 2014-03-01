// primes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

bool is_prime(int);

char key[1024];

int main(int argc, char* argv[])
{
	int print_threshold = 10000, threshold_interval = 10000;

	for (int i = 0; i < 300000; i++) {
		if (is_prime(i)) {
			if (i > print_threshold) {
				printf("%d\n", i);
				print_threshold += threshold_interval;
			}
		}
	}

//	printf("Press Enter to continue\n");
//	getchar();
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