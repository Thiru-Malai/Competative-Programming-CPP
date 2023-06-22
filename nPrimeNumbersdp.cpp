// Dynamic Programming To Find Prime Numbers
#include <bits/stdc++.h>
using namespace std;
bool prime[1000001];
int dp[1000001];
void sieve()
{
    memset(dp, 0, sizeof(dp));
    int i, j;
    int n = pow(10, 6);
    for (i = 0; i <= n; i++)
    {
        prime[i] = true;
    }
    prime[0] = false;
    prime[1] = false;
    int f = pow(n, 0.5);
    for (i = 2; i <= f; i++)
    {
        if (prime[i])
        {
            for (j = i; i * j <= n; j++)
            {
                prime[i * j] = false;
            }
        }
    }
    dp[0] = 0;
    dp[1] = 0;
    for (i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            dp[i] = 1 + dp[i - 1];
        }
        else
        {
            dp[i] += dp[i - 1];
        }
    }
}

int main()
{
    sieve();
    for (auto i : dp)
    {
        cout << i << " ";
    }
}