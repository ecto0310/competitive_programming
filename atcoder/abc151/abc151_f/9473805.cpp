// URL: https://atcoder.jp/contests/abc151/submissions/9473805
// Date: Sun, 12 Jan 2020 22:27:11 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> x(n), y(n);
  for (i64 i = 0; i < n; i++)
    cin >> x[i] >> y[i];
  double ans = 1e9;
  for (i64 i = 0; i < n; i++)
    for (i64 j = i + 1; j < n; j++)
      for (i64 k = j + 1; k < n; k++)
      {
        double g, xc, yc;
        g = y[j] * x[i] - y[i] * x[j] + y[k] * x[j] - y[j] * x[k] + y[i] * x[k] - y[k] * x[i];
        xc = (double)((x[i] * x[i] + y[i] * y[i]) * (y[j] - y[k]) + (x[j] * x[j] + y[j] * y[j]) * (y[k] - y[i]) + (x[k] * x[k] + y[k] * y[k]) * (y[i] - y[j])) / (2 * g);
        yc = -(double)((x[i] * x[i] + y[i] * y[i]) * (x[j] - x[k]) + (x[j] * x[j] + y[j] * y[j]) * (x[k] - x[i]) + (x[k] * x[k] + y[k] * y[k]) * (x[i] - x[j])) / (2 * g);
        g = sqrt((xc - x[i]) * (xc - x[i]) + (yc - y[i]) * (yc - y[i]));
        bool ok = true;
        for (i64 l = 0; l < n; l++)
          if (g < sqrt((xc - x[l]) * (xc - x[l]) + (yc - y[l]) * (yc - y[l])))
            ok = false;
        if (ok)
          ans = min(ans, g);
      }
  for (i64 i = 0; i < n; i++)
    for (i64 j = i + 1; j < n; j++)
    {
      double xc = ((double)x[i] + x[j]) / 2, yc = ((double)y[i] + y[j]) / 2;
      double g = 0;
      for (i64 k = 0; k < n; k++)
        g = max(g, sqrt((xc - x[k]) * (xc - x[k]) + (yc - y[k]) * (yc - y[k])));
      ans = min(ans, g);
    }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
