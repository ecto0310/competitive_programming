// URL: https://atcoder.jp/contests/abc147/submissions/8889740
// Date: Tue, 10 Dec 2019 00:47:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  i64 ans = 0, bit = 1;
  for (i64 i = 0; i < 60; i++)
  {
    i64 cnt[2] = {};
    for (i64 j = 0; j < n; j++)
      if (a[j] & (1LL << i))
        cnt[1]++;
      else
        cnt[0]++;
    (ans += (cnt[0] * cnt[1]) % MOD * bit % MOD) %= MOD;
    (bit *= 2) %= MOD;
  }
  cout << ans << endl;
  return 0;
}
