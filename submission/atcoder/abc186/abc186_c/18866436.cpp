// URL: https://atcoder.jp/contests/abc186/submissions/18866436
// Date: Sat, 19 Dec 2020 21:04:54 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  i64 ans = 0;
  for (i64 i = 1; i <= N; i++)
  {
    bool ok = true;
    i64 t = i;
    while (t)
    {
      if (t % 10 == 7)
        ok = false;
      t /= 10;
    }
    t = i;
    while (t)
    {
      if (t % 8 == 7)
        ok = false;
      t /= 8;
    }
    if (ok)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
