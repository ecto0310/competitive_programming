// URL: https://atcoder.jp/contests/abc164/submissions/12363488
// Date: Sun, 26 Apr 2020 21:16:52 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 modpow(i64 a, i64 n, i64 mod)
{
  i64 res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main()
{
  string S;
  cin >> S;
  i64 ans = 0, now = 0;
  vector<i64> cnt(2019);
  cnt[0]++;
  int size = S.size();
  for (i64 i = size - 1; 0 <= i; i--)
  {
    (now = now + (S[i] - '0') * modpow(10, size - i - 1, 2019)) %= 2019;
    ans += cnt[now];
    cnt[now]++;
  }
  cout << ans << endl;
  return 0;
}
