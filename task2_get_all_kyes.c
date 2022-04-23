#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KEYSIZE 16
 
 
void main()
{
    int i;
    time_t t;
    char key[KEYSIZE];
    FILE *f;
    f = fopen("key.txt", "w");
    for (t = 1524013729; t < 1524020929; t++) // Within two hours
    {
        /* Initialize random number generator */
        srand((unsigned)t);

        /* Output 16 random numbers between 0 and 256 */
        for (i = 0; i < KEYSIZE; i++)
        {
            key[i] = rand() % 256;
            fprintf(f, "%.2x", (unsigned char)key[i]);
        }
        fprintf(f, "\n");
    }
}
