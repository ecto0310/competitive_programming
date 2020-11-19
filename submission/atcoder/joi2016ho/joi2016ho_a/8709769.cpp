// URL: https://atcoder.jp/contests/joi2016ho/submissions/8709769
// Date: Sat, 30 Nov 2019 20:51:49 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 n, m, k;
vector<i64> a;
vector<i64> dp;

i64 dfs(i64 pos)
{

  if (pos == n)
    return 0;
  if (dp[pos] != -1)
    return dp[pos];
  i64 ret = 1e18;
  i64 mi = 1e9, ma = 0;
  for (i64 i = pos; i < min(n, pos + m); i++)
  {
    mi = min(mi, a[i]);
    ma = max(ma, a[i]);
    ret = min(ret, dfs(i + 1) + k + (i - pos + 1) * (ma - mi));
  }
  return dp[pos] = ret;
}

int main()
{
  cin >> n >> m >> k;
  a.resize(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  dp.resize(n, -1);
  cout << dfs(0) << endl;
  return 0;
}
