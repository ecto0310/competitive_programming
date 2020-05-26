// URL: https://atcoder.jp/contests/abc156/submissions/10296297
// Date: Sun, 23 Feb 2020 01:25:27 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

i64 modpow(i64 a, i64 n)
{
  i64 res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return res;
}

i64 modinv(i64 a)
{
  i64 b = MOD, u = 1, v = 0;
  while (b)
  {
    i64 t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= MOD;
  if (u < 0)
    u += MOD;
  return u;
}

i64 nCr(i64 n, i64 r)
{
  i64 den = 1, mol = 1;
  for (i64 i = n; i > n - r; i--)
    (den *= i) %= MOD;
  for (i64 i = 1; i < r + 1; i++)
    (mol *= i) %= MOD;
  return den * modinv(mol) % MOD;
}

int main()
{
  i64 n, a, b;
  cin >> n >> a >> b;
  cout << (modpow(2, n) - 1 - nCr(n, a) - nCr(n, b) + 3 * MOD) % MOD << endl;
  return 0;
}
