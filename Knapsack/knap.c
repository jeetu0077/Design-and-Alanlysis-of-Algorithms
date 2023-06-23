#include <stdio.h>
#define MAX(x, y) ((x) >= (y) ? (x) : (y))

int knapsack_dp(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];
    int i, j;
    for (i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (j = 1; j < W + 1; j++)
        dp[0][j] = 0;
    for (i = 1; i < n + 1; i++)
        for (j = 1; j < W + 1; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (wt[i - 1] <= j)
            {
                dp[i][j] = MAX(dp[i][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
            }
        }
    return dp[n][W];
}

int main(int argc, char **argv)
{
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 60;
    int n = sizeof(val) / sizeof(val[0]);

    printf("%d\n", knapsack_dp(W, wt, val, n));

    return 0;
}