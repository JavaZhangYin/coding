/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int main(int argc, string argv[])
{
  // Argument check, either one option or two options can 
  // be used. 
  if (argc != 2 && argc != 3)
    {
      printf("Usage: ./generate n [s]\n");
      return 1;
    }

  // The first option is the number of random numbers 
  // to generate. 
  int n = atoi(argv[1]);

  // The second option is the seed for the random 
  // generator. 
  if (argc == 3)
    {
      srand((unsigned int) atoi(argv[2]));
    }
  else
    {
      srand((unsigned int) time(NULL));
    }

  // Now, generate n random numbers. 
  for (int i = 0; i < n; i++)
    {
      printf("%i\n", rand() % LIMIT);
    }

  return 0;
}
