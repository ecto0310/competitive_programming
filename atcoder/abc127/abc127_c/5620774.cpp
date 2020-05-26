// URL: https://atcoder.jp/contests/abc127/submissions/5620774
// Date: Sun, 26 May 2019 00:21:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  i64 ll = 0, rr = 1e9;
  for (i64 i = 0; i < m; i++)
  {
    i64 l, r;
    cin >> l >> r;
    ll = max(ll, l);
    rr = min(rr, r);
  }
  cout << max(0LL, rr - ll + 1) << endl;
  return 0;
}
