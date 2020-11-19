// URL: https://atcoder.jp/contests/jsc2019-qual/submissions/7114901
// Date: Sat, 24 Aug 2019 21:49:34 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

i64 modinv(i64 a, i64 m)
{
  i64 b = m, u = 1, v = 0;
  while (b)
  {
    i64 t = a / b;
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
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  vector<i64> cnt(2 * n);
  for (i64 i = 0; i < 2 * n; i++)
    for (i64 j = 0; j < i; j++)
      if (a[i % n] < a[j % n])
        cnt[i]++;
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    i64 tmp = k * (2 * cnt[i] + ((k - 1) * (cnt[i + n] - cnt[i]) % MOD)) % MOD;
    ans += tmp * modinv(2, MOD) % MOD;
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
