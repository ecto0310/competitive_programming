// URL: https://atcoder.jp/contests/diverta2019-2/submissions/6004555
// Date: Tue, 18 Jun 2019 08:24:37 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> x(n), y(n);
  for (i64 i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  map<pair<i64, i64>, i64> m;
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      if (i != j && (x[i] != x[j] || y[i] != y[j]))
        m[{x[i] - x[j], y[i] - y[j]}]++;
  i64 ans = 0;
  for (pair<pair<i64, i64>, i64> i : m)
    ans = max(ans, i.second);
  cout << n - ans << endl;
  return 0;
}
