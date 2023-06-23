#include<stdio.h>
#define MIN(X,Y) (((X) < (Y)) ? (X) : (Y))

void coinChange(int coins[], int total, int n)
{
    int dp[n][total+1];
    for(int i = 0; i < n; i++)
        dp[i][0] = 0;
    for(int i = 1; i < total+1; i++)
        dp[0][i] = i;
        
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < total+1; j++)
        {
            if(coins[i] > j)
                dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = MIN(dp[i-1][j], dp[i][j-coins[i]]+1);
            }
         }
     }
     
     
     for(int i = 0; i < n; i++)
     {
        for(int j = 0; j < total+1; j++)
           printf("%d ", dp[i][j]);
        printf("\n");
     }
     
     printf("\nCoins Requires: %d\n", dp[n-1][total]);
     
     int i = n-1;
     int j = total;
     int mini = dp[i][j];
     while(j != 0)
     {
        if(dp[i-1][j] == mini)
           i--;
        else
        {
            printf("%d\t", coins[i]);
            j = j-coins[i];
            mini = dp[i][j];
        }
     } 
}     

int main()
{
    int coins[] = {1,5,10,25};
    int total = 69;
    int coins_length = sizeof(coins)/sizeof(coins[0]);
    coinChange(coins, total, coins_length);
}