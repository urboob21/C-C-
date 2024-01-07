// register callback fnc

#include <stdio.h>

int callBackFunction(int (*ptr_function)(int, int), int paramFnc1, int paramFnc2)
{
    return ptr_function(paramFnc1, paramFnc2);
}




//-----------------------------------// here is main
int userFunction(int val1, int val2)
{
    printf("User function executed!!!! \n");
    return val1 + val2;
}

int main()
{
    int result = callBackFunction(userFunction, 3, 5);
    printf("Result: %d", result);

    return 0;
}