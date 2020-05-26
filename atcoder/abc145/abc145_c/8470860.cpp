// URL: https://atcoder.jp/contests/abc145/submissions/8470860
// Date: Sat, 16 Nov 2019 21:10:42 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<pair<i64, i64>> p(n);
  for (i64 i = 0; i < n; i++)
    cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end());
  double ans = 0;
  do
  {
    for (i64 i = 0; i < n - 1; i++)
      ans += sqrt((p[i].first - p[i + 1].first) * (p[i].first - p[i + 1].first) + (p[i].second - p[i + 1].second) * (p[i].second - p[i + 1].second));
  } while (next_permutation(p.begin(), p.end()));
  for (i64 i = 1; i <= n; i++)
    ans /= i;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
