// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3863272
// Date: Thu, 12 Sep 2019 22:53:45 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

i64 h, n;
vector<i64> obj;
vector<vector<i64>> dp;

i64 dfs(i64 hn, i64 s)
{
  if (hn == h)
    return 0;
  if (dp[hn][s] != -1)
    return dp[hn][s];
  i64 ans = dfs(hn + 1, obj[hn]);
  for (i64 i = 0; i < 3; i++)
  {
    if (((s >> i) & 3) || ((obj[hn] >> i) & 3))
      continue;
    ans = max(ans, dfs(hn + 1, obj[hn] | (3 << i)) + 1);
  }
  if (s == 0 && obj[hn] == 0)
    ans = max(ans, dfs(hn + 1, (1 << 4) - 1) + 2);
  return dp[hn][s] = ans;
}

int main()
{
  cin >> h >> n;
  obj.resize(h);
  for (i64 i = 0; i < n; i++)
  {
    i64 x, y;
    cin >> x >> y;
    obj[y] |= (1 << x);
  }
  dp.resize(h, vector<i64>(16, -1));
  cout << dfs(1, obj[0]) << endl;
  return 0;
}
