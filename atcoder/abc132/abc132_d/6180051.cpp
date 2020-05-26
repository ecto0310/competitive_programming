// URL: https://atcoder.jp/contests/abc132/submissions/6180051
// Date: Sat, 29 Jun 2019 22:15:40 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

long long modinv(long long a, long long m)
{
  long long b = m, u = 1, v = 0;
  while (b)
  {
    long long t = a / b;
    a -= t * b;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  u %= m;
  if (u < 0)
    u += m;
  return u;
}

int main()
{
  vector<i64> f(4010, 1);
  for (i64 i = 2; i < 4010; i++)
    f[i] = f[i - 1] * i % MOD;
  i64 n, k;
  cin >> n >> k;
  for (i64 i = 1; i <= k; i++)
  {
    i64 b = k - i, r = n - k - (i - 1);
    if (0 <= r)
      cout << (((f[b + i - 1] * modinv((f[b] * f[i - 1]) % MOD, MOD)) % MOD) * ((f[r + i] * modinv((f[r] * f[i]) % MOD, MOD)) % MOD)) % MOD << endl;
    else
      cout << 0 << endl;
  }
  return 0;
}
