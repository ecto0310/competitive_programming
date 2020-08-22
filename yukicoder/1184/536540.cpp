// URL: https://yukicoder.me/submissions/536540
// Date: Sat, 22 Aug 2020 13:10:59 +0900
// Language: C++17(1z)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const i64 MOD = 998244353;

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

int main()
{
  i64 N, L;
  cin >> N >> L;
  N = (N + L - 1) / L;
  cout << (modpow(2, N) - 1 + MOD) % MOD << endl;
  return 0;
}
