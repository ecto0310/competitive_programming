// URL: https://atcoder.jp/contests/abc133/submissions/6281544
// Date: Sun, 07 Jul 2019 21:36:34 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const i64 MOD = 2019;

int main()
{
  i64 l, r;
  cin >> l >> r;
  i64 ans = 1e18;
  for (i64 i = l; i <= min(r, l + MOD * 2); i++)
    for (i64 j = i + 1; j <= min(r, l + MOD * 2); j++)
      ans = min(ans, i * j % MOD);
  cout << ans << endl;
  return 0;
}
