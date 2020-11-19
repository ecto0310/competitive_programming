// URL: https://atcoder.jp/contests/agc002/submissions/5878040
// Date: Tue, 11 Jun 2019 17:59:40 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<bool> c(n);
  vector<i64> cnt(n, 1);
  c[0] = true;
  for (i64 i = 0; i < m; i++)
  {
    i64 x, y;
    cin >> x >> y;
    cnt[x - 1]--;
    cnt[y - 1]++;
    if (c[x - 1])
      c[y - 1] = true;
    if (cnt[x - 1] == 0)
      c[x - 1] = false;
  }
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    if (c[i])
      ans++;
  cout << ans << endl;
  return 0;
}
