#include "lab.h"
#include <stdio.h>
#include <stdlib.h>

char *get_greeting(const char *restrict name)
{
  // MEMORY LEAK
  //char *memLeak = malloc(512);
  
  if (name == NULL)
  {
    return NULL;
  }

  // Allocate memory for the greeting message
  int length = snprintf(NULL, 0, "Hello, %s!", name);
  if (length < 0) // GCOVR_EXCL_START
  {
    return NULL; // snprintf failed
  } // GCOVR_EXCL_STOP

  //Casting is safe here because we know length is non-negative
  size_t alloc_size = (size_t) length + 1; // +1 for the null terminator
  char *greeting = malloc( alloc_size);


  if (greeting == NULL) // GCOVR_EXCL_START
  {
    return NULL; // Memory allocation failed
  }  // GCOVR_EXCL_STOP


  // Create the greeting message
  snprintf(greeting, alloc_size, "Hello, %s!", name);

  return greeting;
}

// Takes in two numbers, returns product of these nums
int getProduct(int num1, int num2) {
  int product = num1 * num2;
  return product;
}

// Returns an incorrect sum of two nums. It will be one more than the correct sum
int getIncorrectSum(int num1, int num2) {
  int incorrectSum = num1 + num2 + 1;
  return incorrectSum;
}