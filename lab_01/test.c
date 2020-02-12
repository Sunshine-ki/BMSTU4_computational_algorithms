#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

void fill_file()
{
    // FILE *f = fopen("test.txt", "w");

    // for (double i = -1; i <= 1; i += 0.25)
    // {`
    //     printf("%lf %lf \n", i, cos(PI / 2 * i));
    // }
    for (int i = -5; i < 5; i++)
        printf("%d %d\n", i, i);

    // fclose(f);
}

int main()
{
    fill_file();
}