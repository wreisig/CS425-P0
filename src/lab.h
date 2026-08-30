#ifndef LAB_H
#define LAB_H

/** * @brief Returns a greeting message.
 *
 * This function returns a string that contains a greeting message.
 * The string is allocated with malloc and should be freed by the caller.
 * @param name The name to include in the greeting.
 * @return A greeting string.
 */
char* get_greeting(const char* restrict name);

// function header for product
int getProduct(int num1, int num2);

// func header for returning incorrect sum of two nums
int getIncorrectSum(int num1, int num2);


#endif // LAB_H
