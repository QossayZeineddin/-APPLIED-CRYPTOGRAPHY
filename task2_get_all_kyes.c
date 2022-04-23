#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define KEYSIZE 16
#define START 1524013729
#define END 1524020929
void main()
{
    int i;
    time_t t;
    char key[KEYSIZE];
    FILE *f;
    f = fopen("possible_key.txt", "w");
    for (t = START; t < END; t++) // Within two hours
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
