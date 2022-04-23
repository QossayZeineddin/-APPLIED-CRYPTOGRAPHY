
#include <stdio.h>
#include <stdlib.h>
#define LEN 32 //  256  bits  (16 * 2 )

void main()
{


    unsigned char *key = (unsigned char *)malloc(sizeof(unsigned char) * LEN);
    FILE *random = fopen("/dev/urandom", "r");
    for (int j = 0; j < LEN; j++)
    {
        fread(key, sizeof(unsigned char) * LEN, 1, random);
        printf("%.2x ", *key);
    }
    printf("\n");
    fclose(random);
}
