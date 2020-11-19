// URL: https://atcoder.jp/contests/abc017/submissions/4927877
// Date: Fri, 12 Apr 2019 21:08:51 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<i64> sum(m);
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    i64 l, r, s;
    cin >> l >> r >> s;
    sum[l - 1] += s;
    sum[r] -= s;
    ans += s;
  }
  i64 mi = sum[0];
  for (i64 i = 1; i < m; i++)
  {
    sum[i] += sum[i - 1];
    mi = min(mi, sum[i]);
  }
  cout << ans - mi << endl;
  return 0;
}
