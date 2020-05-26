// URL: https://atcoder.jp/contests/joi2020yo2/submissions/8922526
// Date: Thu, 12 Dec 2019 18:17:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 sum(i64 n)
{
  i64 ret = 0;
  while (n)
  {
    ret += n % 10;
    n = n / 10;
  }
  return ret;
}

int main()
{
  i64 n;
  cin >> n;
  i64 ans = 0;
  vector<i64> ok(n + 1, -1);
  ok[n] = 1;
  for (i64 i = n; 1 <= i; i--)
  {
    i64 t = i;
    while (t + sum(t) <= n)
    {
      if (ok[t + sum(t)] == 0)
      {
        ok[t] = 0;
        break;
      }
      if (ok[t + sum(t)] == 1)
      {
        ok[t] = 1;
        break;
      }
      t += sum(t);
    }
    if (ok[i] == 1)
      ans++;
    else
      ok[i] = 0;
  }
  cout << ans << endl;
  return 0;
}
