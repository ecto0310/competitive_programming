// URL: https://atcoder.jp/contests/abc158/submissions/10655560
// Date: Sun, 08 Mar 2020 12:36:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

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
  i64 N, P;
  string S;
  cin >> N >> P >> S;
  i64 ans = 0, now = 0;
  if (P == 2 || P == 5)
  {
    for (i64 i = 0; i < N; i++)
      if ((S[i] - '0') % P == 0)
        ans += i + 1;
  }
  else
  {
    vector<i64> cnt(P);
    cnt[0]++;
    for (i64 i = N - 1; 0 <= i; i--)
    {
      (now = now + (S[i] - '0') * modpow(10, N - i - 1, P)) %= P;
      ans += cnt[now];
      cnt[now]++;
    }
  }
  cout << ans << endl;
  return 0;
}
