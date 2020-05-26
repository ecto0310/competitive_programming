// URL: https://atcoder.jp/contests/code-festival-2018-final-open/submissions/8565201
// Date: Sat, 23 Nov 2019 12:36:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  vector<long double> p(1e5 + 5, 0);
  for (i64 i = 1; i < 1e5 + 5; i++)
    p[i] = p[i - 1] + log10(i);
  i64 n, m;
  cin >> n >> m;
  long double ans = log10(m) * n - p[n];
  for (i64 i = 0; i < m; i++)
  {
    i64 r;
    cin >> r;
    ans += p[r];
  }
  cout << ceil(ans) << endl;
  return 0;
}
