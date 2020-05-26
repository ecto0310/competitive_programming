// URL: https://atcoder.jp/contests/abc132/submissions/6165638
// Date: Sat, 29 Jun 2019 21:11:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> p(n);
  for (i64 i = 0; i < n; i++)
    cin >> p[i];
  i64 ans = 0;
  for (i64 i = 1; i < n - 1; i++)
    if (p[i] == p[i - 1] + p[i] + p[i + 1] - max({p[i - 1], p[i], p[i + 1]}) - min({p[i - 1], p[i], p[i + 1]}))
      ans++;
  cout << ans << endl;
  return 0;
}
