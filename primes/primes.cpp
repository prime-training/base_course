
#include <stdio.h>

bool is_prime(int x);
int  atoi(char const *);

int main(int argc, char* argv[])
{
  int end = 100;

  if (argc >= 2) {
    end = atoi(argv[1]);
  }

  printf("Computing primes 2 - %d\n", end);

  int count = 0;
  for (int x = 2; x <= end; ++x) {
    if (is_prime(x)) {
      count += 1;

      printf("prime %6d: %10d\n", count, x);
    }
  }
}

bool is_prime(int x)
{
  // If any number divides x, then it is not prime
  for (int i = 2; i < x; ++i) {
    if ((x % i) == 0) {
      return false;
    }
  }

  return true;
}

int  atoi(char const * str)
{
  int n = 0;

  for (; *str >= '0' && *str <= '9'; ++str) {
    n = 10 * n + (*str - '0');
  }

  return n;
}

