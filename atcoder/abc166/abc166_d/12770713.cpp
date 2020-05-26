// URL: https://atcoder.jp/contests/abc166/submissions/12770713
// Date: Sun, 03 May 2020 22:31:29 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 pow(i64 x, i64 n)
{
  i64 res = 1;
  if (n > 0)
  {
    res = pow(x, n / 2);
    if (n % 2 == 0)
    {
      res = (res * res);
    }
    else
    {
      res = ((res * res) * x);
    }
  }
  return res;
}

int main()
{
  i64 X;
  cin >> X;
  for (i64 i = 0;; i++)
  {
    i64 t = pow(i, 5);
    for (i64 j = 0; pow(j, 5) <= abs(X - t); j++)
      if (abs(X - t) == pow(j, 5))
      {
        if (0 < X - t)
          cout << i << " " << -j << endl;
        else
          cout << i << " " << j << endl;
        return 0;
      }
  }
  return 0;
}
