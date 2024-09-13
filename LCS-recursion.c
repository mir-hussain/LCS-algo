#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int max(int a, int b);
int lcs(char *X, char *Y, int i, int j);

int main()
{
    char X[] = "BADSFAFAGHGJKOOID";
    char Y[] = "ABOIYIUUOYIPFDKDO";
    int i = 0, j = 0;

    clock_t start = clock();

    int length = lcs(X, Y, i, j);

    clock_t end = clock();

    double execution_time = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

    printf("Length = %d \n", length);
    printf("Execution time after 1 iteration = %.0f Miliseconds\n", execution_time);

    return 0;
}

int lcs(char *X, char *Y, int i, int j)
{
    if (X[i] == 0 || Y[j] == 0)
        return 0;
    if (X[i] == Y[j])
        return 1 + lcs(X, Y, i + 1, j + 1);
    else
        return max(lcs(X, Y, i, j + 1), lcs(X, Y, i + 1, j));
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}
