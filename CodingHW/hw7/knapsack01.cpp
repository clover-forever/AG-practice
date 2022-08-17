#include <bits/stdc++.h>

using namespace std;

int DP(int scores[], int costTimes[], int n, int totalTime)
{
  int dp[totalTime + 1];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++)
  {
    for (int j = totalTime; j >= costTimes[i]; j--)
    {
      dp[j] = max(dp[j], scores[i] + dp[j - costTimes[i]]);
    }
  }
  return dp[totalTime];
}

int main()
{
  int n, totalTime;
  cin >> n >> totalTime;
  int scores[n], costTimes[n];
  for (int i = 0; i < n; i++)
  {
    cin >> scores[i] >> costTimes[i];
  }
  cout << DP(scores, costTimes, n, totalTime) << "\n";
  return 0;
}