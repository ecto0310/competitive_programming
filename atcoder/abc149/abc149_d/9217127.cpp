// URL: https://atcoder.jp/contests/abc149/submissions/9217127
// Date: Sun, 29 Dec 2019 20:29:32 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k, r, p, s;
  string t;
  cin >> n >> k >> r >> s >> p >> t;
  i64 ans = 0;
  for (i64 i = 0; i < k; i++)
  {
    vector<vector<i64>> dp(2, vector<i64>(3, 0));
    for (i64 j = i; j < n; j += k)
    {
      if (t[j] == 'r')
        dp[1] = {max(dp[0][1], dp[0][2]), max(dp[0][0], dp[0][2]), max(dp[0][0] + p, dp[0][1] + p)};
      else if (t[j] == 's')
        dp[1] = {max(dp[0][1] + r, dp[0][2] + r), max(dp[0][0], dp[0][2]), max(dp[0][0], dp[0][1])};
      else
        dp[1] = {max(dp[0][1], dp[0][2]), max(dp[0][0] + s, dp[0][2] + s), max(dp[0][0], dp[0][1])};
      swap(dp[0], dp[1]);
    }
    ans += max({dp[0][0], dp[0][1], dp[0][2]});
  }
  cout << ans << endl;
  return 0;
}
