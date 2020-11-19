// URL: https://atcoder.jp/contests/nikkei2019-2-qual/submissions/8658480
// Date: Tue, 26 Nov 2019 16:12:32 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MOD = 998244353;

i64 pow(i64 a, i64 n)
{
  i64 ret = 1;
  while (n)
  {
    if (n % 2 == 1)
      ret = ret * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return ret;
}

int main()
{
  i64 n;
  cin >> n;
  vector<i64> d(n);
  for (i64 i = 0; i < n; i++)
    cin >> d[i];
  i64 dep = 0;
  vector<i64> cnt(n);
  for (i64 i = 0; i < n; i++)
  {
    cnt[d[i]]++;
    dep = max(dep, d[i] + 1);
  }
  if (d[0] != 0 || cnt[0] != 1)
  {
    cout << 0 << endl;
    return 0;
  }
  i64 ans = 1;
  for (i64 i = 2; i < dep; i++)
    ans = ans * pow(cnt[i - 1], cnt[i]) % MOD;
  cout << ans << endl;
  return 0;
}
