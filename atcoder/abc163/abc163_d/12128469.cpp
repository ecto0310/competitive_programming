// URL: https://atcoder.jp/contests/abc163/submissions/12128469
// Date: Sun, 19 Apr 2020 21:35:19 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const i64 MOD = 1e9 + 7;

int main()
{
  i64 N, K;
  cin >> N >> K;
  i64 ans = 0, lim[2] = {0, N};
  for (i64 i = 1; i < K; i++)
  {
    (lim[0] += i) %= MOD;
    (lim[1] += N - i + MOD) %= MOD;
  }
  for (i64 i = K; i <= N + 1; i++)
  {
    (ans += lim[1] - lim[0] + 1 + MOD) %= MOD;
    (lim[0] += i) %= MOD;
    (lim[1] += N - i + MOD) %= MOD;
  }
  cout << ans << endl;
  return 0;
}
