// URL: https://atcoder.jp/contests/abc153/submissions/9754829
// Date: Sun, 26 Jan 2020 21:36:32 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 h, n;
  cin >> h >> n;
  vector<i64> a(n), b(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  vector<i64> dp(h + 1, 1e9);
  dp[0] = 0;
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < h; j++)
      dp[min(h, j + a[i])] = min(dp[min(h, j + a[i])], dp[j] + b[i]);
  cout << dp[h] << endl;
  return 0;
}
