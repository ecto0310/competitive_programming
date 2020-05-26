// URL: https://atcoder.jp/contests/abc002/submissions/4248151
// Date: Wed, 13 Feb 2019 02:51:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int x[3], y[3];
  for (int i = 0; i < 3; i++)
    cin >> x[i] >> y[i];
  double ab = sqrt(pow(x[0] - x[1], 2) + pow(y[0] - y[1], 2)), bc = sqrt(pow(x[1] - x[2], 2) + pow(y[1] - y[2], 2)), ca = sqrt(pow(x[2] - x[0], 2) + pow(y[2] - y[0], 2));
  double s = (ab + bc + ca) / 2;
  cout << fixed << setprecision(8) << sqrt(s * (s - ab) * (s - bc) * (s - ca)) << endl;

  return 0;
}
