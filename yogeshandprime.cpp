// Coding Ninjas
// Yogesh And Prime
// Yogesh is a very intelligent student and is interested in research in Machine Learning domain. His college has only one professor, Mr. Peter working in that field. He approaches the professor for the same, but professor wants to test him first.
// To pass the test Yogesh must answer Q questions correctly. In all the Q questions, professor gives him three positive integers : A, B and K where A ≤ B.
// Now Yogesh has to find an integer P such that it is closest to integer A and there are at least K prime numbers in range [A, P], where A <= P <= B.
// Help Yogesh to find and print minimum possible P or print -1 if there no such possible integer.
// Note: A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.


// Input
// 5
// 2 5 1
// 2 5 2
// 4 12 2
// 3 17 7
// 5 5 1

// Output
// 2
// 3
// 7
// -1
// 5


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
    // cout << dp[5] << endl;
}
int main()
{
    int q;
    cin >> q;
    sieve();
    // cout << dp[5] << endl;
    while (q--)
    {
        int a, b, k;
        cin >> a >> b >> k;
        int start = a, end = b;
        int ans = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (dp[mid] - dp[a - 1] >= k)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}