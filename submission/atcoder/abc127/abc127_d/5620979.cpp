// URL: https://atcoder.jp/contests/abc127/submissions/5620979
// Date: Sun, 26 May 2019 00:30:51 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  vector<pair<i64, i64>> p(m);
  for (i64 i = 0; i < m; i++)
    cin >> p[i].second >> p[i].first;
  sort(a.begin(), a.end());
  sort(p.begin(), p.end(), greater<pair<i64, i64>>());
  i64 now = 0;
  for (i64 i = 0; i < n; i++)
    if (now < m && a[i] < p[now].first)
    {
      a[i] = p[now].first;
      p[now].second--;
      if (p[now].second == 0)
        now++;
    }
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    ans += a[i];
  cout << ans << endl;
  return 0;
}
