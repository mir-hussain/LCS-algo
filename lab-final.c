#include <stdio.h>
#include <string.h>

int max(int x, int y);
int lcs(char *X, char *Y);
void restore_communication(char signals[][100], int city_count);

int main()
{
    int city_count;
    printf("Enter the number of cities: ");
    scanf("%d", &city_count);

    char signals[city_count][100];

    printf("Enter the signals for each city:\n");
    for (int i = 0; i < city_count; i++)
    {
        printf("City %d: ", i + 1);
        scanf("%s", signals[i]);
    }

    restore_communication(signals, city_count);

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

void restore_communication(char signals[][100], int city_count)
{
    int lcs_results[city_count][city_count];

    for (int i = 0; i < city_count; i++)
    {
        for (int j = i + 1; j < city_count; j++)
        {
            lcs_results[i][j] = lcs(signals[i], signals[j]);
        }
    }

    for (int i = 0; i < city_count; i++)
    {
        for (int j = i + 1; j < city_count; j++)
        {
            printf("City %d and City %d: LCS Length = %d\n", i + 1, j + 1, lcs_results[i][j]);
        }
    }
}
