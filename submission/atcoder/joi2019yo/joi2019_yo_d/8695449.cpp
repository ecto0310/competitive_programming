// URL: https://atcoder.jp/contests/joi2019yo/submissions/8695449
// Date: Fri, 29 Nov 2019 16:35:06 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<pair<i64, i64>> a(n);
  for (i64 i = 0; i < n; i++)
  {
    i64 t;
    cin >> t;
    a[i] = {t, i};
  }
  sort(a.begin(), a.end());
  i64 ans = 1, cnt = 1;
  if (a[0].first == 0)
    ans = 0;
  vector<bool> ok(n, true);
  for (i64 i = 0; i < n; i++)
  {
    i64 pos = a[i].second;
    ok[pos] = false;
    cnt--;
    if (0 < pos && ok[pos - 1])
      cnt++;
    if (pos < n - 1 && ok[pos + 1])
      cnt++;
    if (i + 1 == n || a[i].first != a[i + 1].first)
      ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
