// URL: https://atcoder.jp/contests/abc130/submissions/5968035
// Date: Sun, 16 Jun 2019 21:32:41 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  i64 ans = n * (n + 1) / 2;
  i64 sum = 0, r = 0;
  for (i64 l = 0; l < n; l++)
  {
    while (r < n && sum + a[r] < k)
    {
      sum += a[r];
      r++;
    }
    ans -= r - l;
    if (r == l)
      r++;
    else
      sum -= a[l];
  }
  cout << ans << endl;
  return 0;
}
