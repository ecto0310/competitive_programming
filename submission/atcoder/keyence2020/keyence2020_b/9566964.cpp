// URL: https://atcoder.jp/contests/keyence2020/submissions/9566964
// Date: Sat, 18 Jan 2020 21:17:34 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<pair<i64, i64>> r(n);
  for (i64 i = 0; i < n; i++)
  {
    i64 x, l;
    cin >> x >> l;
    r[i] = {x + l, x - l};
  }
  sort(r.begin(), r.end());
  i64 ans = 0, now = -1e10;
  for (i64 i = 0; i < n; i++)
    if (now <= r[i].second)
    {
      ans++;
      now = r[i].first;
    }
  cout << ans << endl;
  return 0;
}
