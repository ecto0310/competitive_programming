// URL: https://codeforces.com/contest/1195/submission/57232064
// Date: Thu, 18 Jul 2019 01:05:45 +0900
// Language: GNU C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const i64 MOD = 998244353;

int main()
{
  i64 n;
  cin >> n;
  vector<string> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  i64 ans = 0;
  i64 size = a[0].size();
  for (i64 i = 0; i < n; i++)
  {
    i64 tmp = 0;
    for (i64 j = 0; j < size; j++)
    {
      tmp += (a[i][j] - '0');
      tmp *= 100;
      if (j + 1 == size)
        tmp /= 10;
      tmp %= MOD;
    }
    ans += tmp * n % MOD;
    ans %= MOD;
    tmp = 0;
    for (i64 j = 0; j < size; j++)
    {
      tmp *= 100;
      tmp += (a[i][j] - '0');
      tmp %= MOD;
    }
    ans += tmp * n % MOD;
    ans %= MOD;
  }
  cout << ans % MOD << endl;
  return 0;
}
