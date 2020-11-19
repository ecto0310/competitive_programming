// URL: https://atcoder.jp/contests/abc144/submissions/8240093
// Date: Fri, 01 Nov 2019 21:13:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

bool ok(i64 c, i64 k, vector<i64> a, vector<i64> f)
{
  i64 cnt = 0;
  i64 size = a.size();
  for (i64 i = 0; i < size; i++)
    if (c < a[i] * f[i])
      cnt += a[i] - c / f[i];
  return cnt <= k;
}

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n), f(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  for (i64 i = 0; i < n; i++)
    cin >> f[i];
  sort(a.begin(), a.end());
  sort(f.begin(), f.end(), greater<i64>());
  i64 l = -1, r = 1e18;
  for (i64 _ = 0; _ < 100; _++)
  {
    i64 mid = (l + r) / 2;
    if (ok(mid, k, a, f))
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;
  return 0;
}
