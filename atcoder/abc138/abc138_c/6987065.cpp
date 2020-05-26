// URL: https://atcoder.jp/contests/abc138/submissions/6987065
// Date: Sun, 18 Aug 2019 21:06:45 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> v(n);
  for (i64 i = 0; i < n; i++)
    cin >> v[i];
  sort(v.begin(), v.end());
  double ans = (double)(v[0] + v[1]) / 2;
  for (i64 i = 2; i < n; i++)
    ans = (ans + v[i]) / 2;
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
