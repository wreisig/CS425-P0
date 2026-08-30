#include "lab.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef TEST
#define main main_exclude
#endif



int main(void)
{
    // // Code for testing crash
    // int crashNum1 = 1;
    // int *crashNumPointer1;

    // crashNumPointer1 = &crashNum1;

    // crashNumPointer1 = NULL;

    // // Debug build crashes from this null pointer deref, release build doesn't
    // int crashNum2 = *crashNumPointer1;

    char *greeting = get_greeting("World");
    if (greeting) {
        printf("%s\n", greeting);
        free(greeting); // Free the allocated memory for the greeting
    } else {
        printf("Failed to create greeting.\n");
    }

    //MEMORY LEAK
    //char *memLeak = malloc(512);

    return 0;
}