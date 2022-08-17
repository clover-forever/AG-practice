#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#define inf 0xffffff
using namespace std;
const int maxn = 2 * 1e6 + 7;
int dp[maxn];
int a[maxn];
int max_array[maxn];
int main()
{
    int m = 2, n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    memset(dp, 0, sizeof(dp));
    memset(max_array, 0, sizeof(max_array));
    int res;
    for (int i = 1; i <= m; i++)
    {
        res = -inf;
        for (int j = i; j <= n; j++)
        {
            if (i == j)
                dp[j] = max_array[j - 1] + a[j];
            else
                dp[j] = max(dp[j - 1], max_array[j - 1]) + a[j];

            max_array[j - 1] = res;
            if (res < dp[j])
                res = dp[j];
        }
    }

    printf("%d\n", res);

    return 0;
}