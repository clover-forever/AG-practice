#include <bits/stdc++.h>
using namespace std;
long long ways_tile_floor(int N, int M)
{
  long long arr[N + 1];
  arr[0] = 0;
  for (int i = 1; i <= N; i++)
  {
    if (i > M)
    {
      arr[i] = arr[i - 1] + arr[i - M];
    }
    else if (i < M || i == 1)
    {
      arr[i] = 1;
    }
    else
    {
      arr[i] = 2;
    }
  }
  return arr[N];
}
int main()
{
  int n;
  cin >> n;
  int m = 2;
  cout << ways_tile_floor(n, m);
  return 0;
}

