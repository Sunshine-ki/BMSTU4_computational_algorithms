#include <stdio.h>
#include <math.h>

#include "headers/define.h"

#define START -1
#define STOP 1
#define STEP 0.25

void fill_file()
{
    FILE *f = fopen("table/test.txt", "w");

    fprintf(f, "%d\n", (int)fabs(((STOP - START) / STEP + 1)));
    for (double i = START; i <= STOP; i += STEP)
        fprintf(f, "%f %f\n", i, FUNC(i));

    fclose(f);
}

void main()
{
    fill_file();
}
