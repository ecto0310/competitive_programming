// URL: https://atcoder.jp/contests/joi2009ho/submissions/18447162
// Date: Sat, 28 Nov 2020 16:58:16 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 d, n, m;
  cin >> d >> n >> m;
  vector<i64> s(n + 1), k(m);
  for (i64 i = 1; i < n; i++)
    cin >> s[i];
  s[n] = d;
  for (i64 i = 0; i < m; i++)
    cin >> k[i];
  sort(s.begin(), s.end());
  i64 ans = 0;
  for (i64 i = 0; i < m; i++)
  {
    i64 it = lower_bound(s.begin(), s.end(), k[i]) - s.begin();
    ans += min(abs(s[it] - k[i]), (it == 0 ? (i64)1e9 : abs(s[it - 1] - k[i])));
  }
  cout << ans << endl;
  return 0;
}
