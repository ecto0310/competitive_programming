// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3730033
// Date: Tue, 09 Jul 2019 17:04:43 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

i64 n;
vector<i64> x, r;

double f(double p)
{
  double ret = 1e18;
  for (i64 i = 0; i < n; i++)
  {
    double d = abs(p - x[i]);
    ret = min(ret, sqrt((double)r[i] * r[i] - d * d));
  }
  return ret;
}

int main()
{
  cin >> n;
  x.resize(n);
  r.resize(n);
  for (i64 i = 0; i < n; i++)
    cin >> x[i] >> r[i];
  double a = -1e18, b = 1e18;
  for (i64 i = 0; i < n; i++)
  {
    a = max(a, (double)x[i] - r[i]);
    b = min(b, (double)x[i] + r[i]);
  }
  while (0.00001 < b - a)
  {
    if (f((a * 2 + b) / 3) < f((a + b * 2) / 3))
      a = (a * 2 + b) / 3;
    else
      b = (a + b * 2) / 3;
  }
  cout << fixed << setprecision(4) << f(b) << endl;
  return 0;
}
