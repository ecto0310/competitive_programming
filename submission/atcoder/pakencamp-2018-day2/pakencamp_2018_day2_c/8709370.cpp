// URL: https://atcoder.jp/contests/pakencamp-2018-day2/submissions/8709370
// Date: Sat, 30 Nov 2019 20:24:45 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  for (i64 i = 1; i <= n; i++)
  {
    vector<i64> t(i, 0);
    bool ok = true;
    for (i64 j = 0; j < n; j++)
      if (a[j] != 0)
      {
        if (t[j % i] == 0)
          t[j % i] = a[j];
        if (a[j] != t[j % i])
          ok = false;
      }
    if (ok)
    {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
