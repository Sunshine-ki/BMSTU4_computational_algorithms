#include <stdio.h>
#include <math.h>

#include "define.h"

void fill_file()
{
    FILE *f = fopen("table/test.txt", "w");

    fprintf(f, "%d\n%-10d ", (int)fabs(((STOP - START) / STEP + 1)), 0);

    for (double i = START; i <= STOP; i += STEP)
        fprintf(f, "%-10f ", i);

    for (double i = START; i <= STOP; i += STEP)
    {
        fprintf(f, "\n%-10f ", i);
        for (double j = START; j <= STOP; j += STEP)

            fprintf(f, "%-10f ", FUNC(i, j));
    }

    fclose(f);
}

void main()
{
    fill_file();
}
