#include <stdio.h>

void some_function(char some_array[])
{
    printf("before reassignment:\n");
    printf("some_array: %p\n", some_array);
    printf("&some_array: %p\n", &some_array);
    printf("some_array: %s\n", some_array);

    some_array = "in function";

    printf("after reassignment:\n");
    printf("some_array: %p\n", some_array);
    printf("&some_array: %p\n", &some_array);
    printf("some_array: %s\n", some_array);
}

int main()
{
    char some_array[] = "array";
    char *some_pointer = "pointer";

    printf("some_array: %p\n", some_array);
    printf("&some_array: %p\n", &some_array);
    printf("some_array: %s\n", some_array);

    printf("some_pointer: %p\n", some_pointer);
    printf("&some_pointer: %p\n", &some_pointer);
    printf("some_pointer: %s\n", some_pointer);

    printf("\n\n");

    some_function(some_array);

    printf("\n\n");

    int int_array[] = {0,0,0};
    printf("int_array: %p\n", int_array);
    printf("&int_array: %p\n", &int_array);

    // this doesn't work!
    int *int_pointer = {1,1,1};
    printf("int_pointer: %p\n", int_pointer);
    printf("&int_pointer: %p\n", &int_pointer);

    return 0;
}
