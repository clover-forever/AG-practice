#include <bits/stdc++.h>
using namespace std;
int N;
int MOD = 1e9 + 7;
long dp1[1001];
long dp2[1001];
long long full(int n);
long long partt(int n);
long long partt(int n)
{
  if (n <= 0)
    return 0;
  if (n == 1)
    return 1;
  if (dp2[n] != -1)
    return dp2[n];

  long long cnt = partt(n - 1) % MOD;
  cnt = (cnt + full(n - 2)) % MOD;
  return dp2[n] = cnt;
}
long long full(int n)
{
  if (n < 0)
    return 0;
  if (n == 0)
    return 1;
  if (n == 1)
    return 2;
  if (dp1[n] != -1)
    return dp1[n];

  long long cnt = full(n - 1) % MOD;
  cnt = (cnt + full(n - 2)) % MOD;
  return dp1[n] = cnt;
}



long long numTilings(int n)
{
  N = n;
  memset(dp1, -1, sizeof(dp1));
  memset(dp2, -1, sizeof(dp2));
  return (long long)full(n - 1);
}
int main()
{
  int n;
  cin >> n;
  
  cout << numTilings(n);
  return 0;
}