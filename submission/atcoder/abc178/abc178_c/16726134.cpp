// URL: https://atcoder.jp/contests/abc178/submissions/16726134
// Date: Sun, 13 Sep 2020 23:35:21 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 MOD = 1e9 + 7;

i64 pow(i64 x, i64 n)
{
  i64 r = 1;
  for (i64 i = 0; i < n; i++)
    r = r * x % MOD;
  return r;
}

int main()
{
  i64 N;
  cin >> N;
  i64 ans = pow(10LL, N) + pow(8LL, N) - pow(9LL, N) * 2;
  cout << (ans + MOD * 2) % MOD << endl;
  return 0;
}
