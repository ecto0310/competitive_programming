// URL: https://atcoder.jp/contests/abc145/submissions/8498676
// Date: Sun, 17 Nov 2019 14:26:10 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

vector<i64> fac(1e6 + 1);
vector<i64> ifac(1e6 + 1);

i64 mpow(i64 x, i64 n)
{
  i64 ans = 1;
  while (n != 0)
  {
    if (n & 1)
      ans = ans * x % MOD;
    x = x * x % MOD;
    n = n >> 1;
  }
  return ans;
}

i64 comb(i64 a, i64 b)
{
  if (a == 0 && b == 0)
    return 1;
  if (a < b || a < 0 || b < 0)
    return 0;
  i64 tmp = ifac[a - b] * ifac[b] % MOD;
  return tmp * fac[a] % MOD;
}

int main()
{
  i64 x, y;
  cin >> x >> y;
  i64 tx = 0, ty = 0;
  fac[0] = 1;
  ifac[0] = 1;
  for (i64 i = 0; i <= 1e6; i++)
  {
    fac[i + 1] = fac[i] * (i + 1) % MOD;
    ifac[i + 1] = ifac[i] * mpow(i + 1, MOD - 2) % MOD;
  }
  for (i64 i = 1; i <= 1e6; i++)
  {
    tx += 2;
    ty += 1;
    if (tx - x == y - ty)
    {
      cout << comb(i, tx - x) << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
