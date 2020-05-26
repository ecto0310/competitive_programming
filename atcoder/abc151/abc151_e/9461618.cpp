// URL: https://atcoder.jp/contests/abc151/submissions/9461618
// Date: Sun, 12 Jan 2020 21:38:41 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

vector<i64> fac(300001);
vector<i64> ifac(300001);

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
  if (a < b || a < 0)
    return 0;
  i64 tmp = ifac[a - b] * ifac[b] % MOD;
  return tmp * fac[a] % MOD;
}

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  fac[0] = 1;
  ifac[0] = 1;
  for (i64 i = 0; i < 300000; i++)
  {
    fac[i + 1] = fac[i] * (i + 1) % MOD;
    ifac[i + 1] = ifac[i] * mpow(i + 1, MOD - 2) % MOD;
  }
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    (ans += comb(i, k - 1) * a[i] - comb(n - i - 1, k - 1) * a[i]) %= MOD;
  cout << ans % MOD << endl;
  return 0;
}
