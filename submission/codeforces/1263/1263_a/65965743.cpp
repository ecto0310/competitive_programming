// URL: https://codeforces.com/contest/1263/submission/65965743
// Date: Fri, 29 Nov 2019 23:55:49 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 t;
  cin >> t;
  for (i64 _ = 0; _ < t; _++)
  {
    vector<i64> c(3);
    cin >> c[0] >> c[1] >> c[2];
    sort(c.begin(), c.end());
    i64 ans = min(c[0] + c[1], c[2]);
    i64 tmp = 0;
    if (c[0] % 2 == 0)
    {
      tmp += min(c[0], c[2] - c[1]);
      c[0] -= tmp;
      c[2] -= tmp;
      tmp += min(c[0] / 2, c[1]);
      c[1] -= min(c[0] / 2, c[1]);
      tmp += min(c[0] / 2, c[2]);
      c[2] -= min(c[0] / 2, c[2]);
      tmp += min(c[1], c[2]);
    }
    else
    {
      tmp += min(c[0], c[2] - c[1]);
      c[0] -= tmp;
      c[2] -= tmp;
      tmp += min(c[0] / 2, c[1]);
      c[1] -= min(c[0] / 2, c[1]);
      tmp += min(c[0] / 2, c[2]);
      c[2] -= min(c[0] / 2, c[2]);
      tmp += min(c[1], c[2]);
    }
    ans = max(ans, tmp);
    cout << ans << endl;
  }
  return 0;
}
