// URL: https://atcoder.jp/contests/abc153/submissions/9758738
// Date: Sun, 26 Jan 2020 21:52:18 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, d, a;
  cin >> n >> d >> a;
  vector<pair<i64, i64>> mob(n);
  for (i64 i = 0; i < n; i++)
    cin >> mob[i].first >> mob[i].second;
  sort(mob.begin(), mob.end());
  vector<i64> cnt(n);
  i64 ans = 0, at = 0;
  for (i64 i = 0; i < n; i++)
  {
    at -= cnt[i];
    mob[i].second -= at * a;
    i64 tmp = (max(0LL, mob[i].second) + a - 1) / a;
    at += tmp;
    ans += tmp;
    i64 it = upper_bound(mob.begin(), mob.end(), make_pair(mob[i].first + 2 * d, (i64)1e9)) - mob.begin();
    if (it < n)
      cnt[it] += tmp;
  }
  cout << ans << endl;
  return 0;
}
