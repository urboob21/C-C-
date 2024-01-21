#include <setjmp.h>
#include <stdio.h>
/**
 * int setjmp(jmp_buf j);
 * - remember where you are now
 * - call first
 * 
 * longjmp(jmp_buf j, int i);
 * 
 * - go back to j set
 * - restore the process at
 * 
 * 
*/
jmp_buf buf;

void error_recovery(){
    printf("detected an error. \n");
    longjmp(buf,1);
}

int main(){
    while (1)
    {
        if(setjmp(buf)){
            printf("Back to main \n");
        }else{
            error_recovery(); 
        }

    }
    
    return 0;
}