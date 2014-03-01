// primes.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

// What is the largest number to look at?
#define LARGEST 150000

// Is the number a prime?
bool is_prime(int n)
{
  // Look at all the numbers between 2 and n
  int i = 2;
  while (i < n) {

    // If it devides evenly, it is not a prime '%' means remainder
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

  // How many primes have we found?
  int count = 0;

  // Loop over the potential primes
  int i = 2;
  while (i < LARGEST) {

    // Test for prime-ness
    if (is_prime(i)) {

      // We've found one!
      count = count + 1;

      // Print, but only some of them
      if (i > print_threshold) {
        printf("%7d -- %d\n", count, i);
        print_threshold += threshold_interval;
      }
    }

    i++;
  }

  //printf("Press Enter to continue\n");
  //getchar();
  return 0;
}

