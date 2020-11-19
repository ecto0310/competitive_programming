// URL: https://atcoder.jp/contests/abc152/submissions/9602869
// Date: Sun, 19 Jan 2020 20:54:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> p(n);
  for (i64 i = 0; i < n; i++)
    cin >> p[i];
  i64 ans = 0, m = 1e9;
  for (i64 i = 0; i < n; i++)
  {
    if (p[i] <= m)
      ans++;
    m = min(m, p[i]);
  }
  cout << ans << endl;
  return 0;
}
