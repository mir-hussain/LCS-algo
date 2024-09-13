#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int max(int x, int y);
int lcs(char *X, char *Y);

int main()
{
    char *X = "BADSFAFAGHGJKOOID";
    char *Y = "ABOIYIUUOYIPFDKDO";

    clock_t start = clock();

    int length = lcs(X, Y);
    int i;
    for (i = 0; i < 100000; i++)
    {
        lcs(X, Y);
    }
    clock_t end = clock();

    double execution_time = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

    printf("Length = %d\n", length);
    printf("Execution time after 100000 iteration = %.0f Miliseconds\n", execution_time);

    return 0;
}

int lcs(char *X, char *Y)
{
    int m = strlen(X);
    int n = strlen(Y);

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}

int max(int x, int y)
{
    return (x > y) ? x : y;
}
