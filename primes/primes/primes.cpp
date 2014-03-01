// primes.cpp : Defines the entry point for the console application.
//

// simplest method results:  13848 --    149993:      987369615

#include <stdio.h>

typedef __int64 int64;

// What is the largest number to look at?
#define LARGEST 150000

// Keep stats on the number of operations done in this run
int64 num_ops = 0;

// Is the number a prime?
bool is_prime(int n)
{
  // Look at all the numbers between 2 and n
  int i = 2;
  while (i < n) {

    // If it devides evenly, it is not a prime '%' means remainder
    num_ops++;
    if (n % i == 0) {
      return false;
    }

    // Look at the next number
    i++;
  }

  // If we get here, the number cannot be divided by any of the numbers
  // less that it, so it is a prime
  return true;
}

/**
 *  The main function
 */
int main(int argc, char* argv[])
{
  // Only print when the number goes above the threshold, for each interval
  int print_threshold = 10000, threshold_interval = 10000;

  int count = 0;    // How many primes have we found?
  int last = 0;     // What is the most current one we've found?

  // Print a header
  printf("%7s -- %9s:  %13s\n", "count", "prime", "num_ops");

  // Loop over the potential primes
  int i = 2;
  while (i < LARGEST) {

    // Test for prime-ness
    if (is_prime(i)) {

      // We've found one!
      last = i;
      count = count + 1;

      // Print, but only some of them
      if (i > print_threshold || i < 1000) {
        printf("%7d -- %9d:  %13I64d\n", count, i, num_ops);
        if (i > print_threshold) {
          print_threshold += threshold_interval;
        }
      }
    }

    i++;
  }

  printf("\n");
  printf("%7d -- %9d:  %13I64d\n", count, last, num_ops);

  printf("Press Enter to continue\n");
  getchar();
  return 0;
}

