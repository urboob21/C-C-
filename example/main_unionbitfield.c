/*
MSB            LSB
 7              0
+---------------+
| 2 bits | 6bits|
+---------------+

send 1byte data: 2 bits cmd + 6 bits data

-> parse


*/
#include "stdio.h"
#include "stdint.h"

typedef struct
{
    //  LSB
    uint8_t cmd : 4 ;
    uint8_t data : 4;
    // MS B
} fields_tag_t;

typedef union
{
    uint8_t rawInput;
    fields_tag_t fields;
} input_data8_t;

int main()
{
    input_data8_t input;
    input.rawInput = 0b11000100; //  raw: 0xc4  
    printf("Value of raw input is: 0x%x \n", input.rawInput); 
    printf("Value of cmd is:  0x%x\n", input.fields.cmd);        // 0x4
    printf("Value of data is:  0x%x \n", input.fields.data);    // 0xc

    return 0;
}