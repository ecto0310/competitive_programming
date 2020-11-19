// URL: https://atcoder.jp/contests/joi2020yo1b/submissions/10402698
// Date: Sat, 29 Feb 2020 17:43:49 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  vector<i64> cnt(m);
  for (i64 i = 0; i < n; i++)
    cnt[a[i] - 1]++;
  i64 ans = 0;
  for (i64 i = 0; i < m; i++)
    ans = max(ans, cnt[i]);
  cout << ans << endl;
}
