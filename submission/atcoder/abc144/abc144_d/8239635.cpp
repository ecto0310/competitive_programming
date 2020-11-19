// URL: https://atcoder.jp/contests/abc144/submissions/8239635
// Date: Fri, 01 Nov 2019 20:38:37 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const double PI = 3.141592653589793;

bool ok(double t, double a, double b, double x)
{
  t *= PI / 180;
  double v;
  if (a < b * cos(t) / sin(t))
    v = a * a * b - a * a * a * sin(t) / cos(t) / 2;
  else
    v = a * b * b * cos(t) / sin(t) / 2;
  return v <= x;
}

int main()
{
  i64 a, b, x;
  cin >> a >> b >> x;
  double l = 0, r = 90;
  for (i64 _ = 0; _ < 100; _++)
  {
    double mid = (l + r) / 2;
    if (ok(mid, (double)a, (double)b, (double)x))
      r = mid;
    else
      l = mid;
  }
  cout << fixed << setprecision(10) << l << endl;
  return 0;
}
