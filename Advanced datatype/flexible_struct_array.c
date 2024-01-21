#include <stdio.h>
#include <malloc.h>
#include <stdint.h>

// Flexible when managed the number of data

typedef struct
{
    uint8_t id;
    uint8_t size;
    uint8_t data[]; // flexible array
} flex_struct_array_t;

int main()
{

    int size = 4;
    // Size of 4 data = size of (Struct = sizeof(int)) + size of(data[] = sizeof 4*int size) = 2 +4*1 = 6
    uint32_t sizeOfDatas = sizeof(flex_struct_array_t) + size * sizeof(uint8_t);
    flex_struct_array_t *blockData = malloc(sizeOfDatas);
    printf("Size of all data: %d \n", sizeOfDatas);

    blockData->id = 1;
    for (int i = 0; i < size; i++)
    {
        blockData->data[i] = i;
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d \n", blockData->data[i]);
    }

    free(blockData);
    return 0;
}