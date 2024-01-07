/*
 * We can specify the size (in bits) of structure and union member -> reduces  memory comsumtion
*
--- syntax

struct
{
    data_type member_name : width_of_bit-field;
};

---
*/
#include <stdint.h>
#include <stdio.h>

struct n_day{
    unsigned int date;      // 16 bit
    unsigned int month;
    unsigned int year;
};

typedef struct f_day{
    unsigned int date : 5 ;                 // 0 - 31: 5bits
    unsigned int month: 4 ;                 // 0 - 12: 4bits
    unsigned int year : 12;                 // 0 - 4000: 12 bits
} f_day_t;

int main(){
    struct n_day    day;
    f_day_t         f_day;

    printf("Size of day is: %d \n", sizeof(day));          // Expected result is: 6 bytes 
    printf("Size of f_day is: %d", sizeof(f_day));          // Expected result is: 4 bytes 

    return 0;
}



