#include <stdlib.h>
#include <stdio.h>
#include "harness/unity.h"
#include "../src/lab.h"


void setUp(void) {
  printf("Setting up tests...\n");
}

void tearDown(void) {
  printf("Tearing down tests...\n");
}

void test_get_greeting(void) {
  char *greeting = get_greeting("Alice");
  TEST_ASSERT_NOT_NULL(greeting);
  TEST_ASSERT_EQUAL_STRING("Hello, Alice!", greeting);
  free(greeting); // Free the allocated memory for the greeting

  greeting = get_greeting(NULL);
  TEST_ASSERT_NULL(greeting);

  greeting = get_greeting("");
  TEST_ASSERT_NOT_NULL(greeting);
  TEST_ASSERT_EQUAL_STRING("Hello, !", greeting);
  free(greeting);
}

void test_getProduct(void) {
  int num1 = 10;
  int num2 = 15;

  // think this doesnt work
  // int product = getProduct(NULL, NULL);
  // TEST_ASSERT_NULL(product);

  int product = getProduct(num1, num2);
  // Assert that product is equal to 15 * 10, which is 150
  TEST_ASSERT_EQUAL_INT(150, product);
}

void test_getIncorrectSum(void) {
  int num1 = 3;
  int num2 = 4;

  int sum = getIncorrectSum(3, 4);

  // Because the function doesn't correctly sum 3 and 4, the sum won't be equal to 7
  TEST_ASSERT_NOT_EQUAL_INT(7, sum);

  // In reality, it's sum of the two numbers + 1, so it'll be 8
  TEST_ASSERT_EQUAL_INT(8, sum);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_get_greeting);
  RUN_TEST(test_getProduct);
  RUN_TEST(test_getIncorrectSum);
  return UNITY_END();
}
