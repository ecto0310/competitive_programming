// URL: https://atcoder.jp/contests/abc099/submissions/3336505
// Date: Fri, 05 Oct 2018 22:31:51 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  int use[12] = {1, 6, 9, 36, 81, 216, 729, 1296, 6561, 7776, 46656, 59049};
  vector<int> dp(200000, 100001);
  dp[0] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 12; j++)
      dp[i + use[j]] = min(dp[i + use[j]], dp[i] + 1);
  cout << dp[n] << endl;

  return 0;
}
