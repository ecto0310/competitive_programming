// URL: https://atcoder.jp/contests/abc128/submissions/5639123
// Date: Sun, 26 May 2019 21:14:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<i64> r[m];
  for (i64 i = 0; i < m; i++)
  {
    i64 k;
    cin >> k;
    r[i].resize(k);
    for (i64 j = 0; j < k; j++)
      cin >> r[i][j];
  }
  vector<i64> p(m);
  for (i64 i = 0; i < m; i++)
    cin >> p[i];
  i64 ans = 0;
  for (i64 i = 0; i < (1 << n); i++)
  {
    bool ok = true;
    for (i64 j = 0; j < m; j++)
    {
      i64 cnt = 0;
      for (i64 k : r[j])
        if (i & (1 << k - 1))
          cnt++;
      if (cnt % 2 != p[j])
        ok = false;
    }
    if (ok)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
