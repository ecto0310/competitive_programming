// URL: https://atcoder.jp/contests/abc023/submissions/9514279
// Date: Wed, 15 Jan 2020 00:47:33 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 r, c, k, n;
  cin >> r >> c >> k >> n;
  vector<i64> x(n), y(n);
  for (i64 i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  vector<i64> cntx(r), cnty(c);
  for (i64 i = 0; i < n; i++)
  {
    cntx[x[i]]++;
    cnty[y[i]]++;
  }
  map<i64, i64> cx, cy;
  for (i64 i = 0; i < r; i++)
    cx[cntx[i]]++;
  for (i64 i = 0; i < c; i++)
    cy[cnty[i]]++;
  i64 ans = 0;
  for (i64 i = 0; i <= k; i++)
    ans += cx[i] * cy[k - i];
  for (i64 i = 0; i < n; i++)
    if (cntx[x[i]] + cnty[y[i]] == k)
      ans--;
    else if (cntx[x[i]] + cnty[y[i]] == k + 1)
      ans++;
  cout << ans << endl;
  return 0;
}
