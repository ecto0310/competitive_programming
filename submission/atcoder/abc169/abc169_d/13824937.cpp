// URL: https://atcoder.jp/contests/abc169/submissions/13824937
// Date: Sun, 31 May 2020 21:26:46 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  map<i64, i64> m;
  i64 tmp = N;
  for (i64 i = 2; i <= sqrt(N); i++)
  {
    while (tmp % i == 0)
    {
      m[i]++;
      tmp /= i;
    }
  }
  if (tmp != 1)
    m[tmp]++;
  i64 ans = 0;
  for (pair<i64, i64> i : m)
  {
    i64 t = 1;
    while (0 <= i.second - t)
    {
      i.second -= t;
      t++;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
