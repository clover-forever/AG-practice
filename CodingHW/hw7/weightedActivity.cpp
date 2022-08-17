#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
  int score, deadline, mins;
};

int main() {
  int n;

  cin >> n;

  vector<Item> items (n);

  int lastMinute = 0;

  for (int i = 0; i < n; i++) {
    cin >> items[i].score >> items[i].deadline >> items[i].mins;
    lastMinute = max(lastMinute, items[i].deadline);
  }
  
  vector<vector<int>> dp (n + 1, vector<int>(lastMinute + 1, 0));

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= lastMinute; j++) {
      if (j - items[i].mins < 0) {
        if (j - 1 < 0)
          dp[i][j] = dp[i + 1][j];
        else
          dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
      }
        
      else if (items[i].deadline < j)
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      else
        dp[i][j] = max({ dp[i][j - 1], dp[i + 1][j], items[i].score + dp[i + 1][j - items[i].mins] });
    }
  }

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j <= lastMinute; j++) {
  //     cout << dp[i][j] << '\t';
  //   }
  //   cout << '\n';
  // }

  cout << dp[0][lastMinute];
}