// URL: https://atcoder.jp/contests/joi2015ho/submissions/9901454
// Date: Tue, 04 Feb 2020 22:52:44 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 n;
vector<i64> a;
vector<vector<i64>> dp;

i64 calc(i64 l, i64 r, bool t)
{
  if (dp[l][r] != -1)
    return dp[l][r];
  if (l == r)
  {
    if (t)
      return dp[l][r] = 0;
    else
      return dp[l][r] = a[l];
  }
  if (t)
  {
    if (a[r] < a[l])
      return dp[l][r] = calc((l + 1) % n, r, false);
    else
      return dp[l][r] = calc(l, (r + n - 1) % n, false);
  }
  return dp[l][r] = max(calc((l + 1) % n, r, true) + a[l], calc(l, (r + n - 1) % n, true) + a[r]);
}

int main()
{
  cin >> n;
  a.resize(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  dp.resize(n, vector<i64>(n, -1));
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    ans = max(ans, calc((i + 1) % n, (i + n - 1) % n, true) + a[i]);
  cout << ans << endl;
  return 0;
}
