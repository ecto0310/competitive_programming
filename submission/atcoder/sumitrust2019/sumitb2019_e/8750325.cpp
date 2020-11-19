// URL: https://atcoder.jp/contests/sumitrust2019/submissions/8750325
// Date: Sun, 01 Dec 2019 23:02:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  i64 ans = 1, c[3] = {};
  for (i64 i = 0; i < n; i++)
  {
    i64 cnt = 0, t = -1;
    if (a[i] == c[0])
    {
      cnt++;
      t = 0;
    }
    if (a[i] == c[1])
    {
      cnt++;
      t = 1;
    }
    if (a[i] == c[2])
    {
      cnt++;
      t = 2;
    }
    if (t == -1)
    {
      cout << 0 << endl;
      return 0;
    }
    (ans *= cnt) %= MOD;
    c[t]++;
  }
  cout << ans << endl;
  return 0;
}
