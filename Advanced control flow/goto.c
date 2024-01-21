#include <stdio.h>
int main()
{
    for (;;)
    {
        for (;;)
        {
            for (;;)
            {
                goto exit;
            }
        }
    }
exit:
    printf("Hello world");

    return 0;
}