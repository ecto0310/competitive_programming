// URL: https://atcoder.jp/contests/abc179/submissions/16905881
// Date: Sun, 20 Sep 2020 15:34:07 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const i64 MOD = 998244353;

int main()
{
  i64 N, K;
  cin >> N >> K;
  vector<i64> L(N), R(N);
  for (i64 i = 0; i < N; i++)
    cin >> L[i] >> R[i];
  vector<i64> dp(N + 1), sumDp(N + 1);
  dp[1] = 1, sumDp[1] = 1;
  for (i64 i = 2; i <= N; i++)
  {
    for (i64 j = 0; j < K; j++)
      (dp[i] += (sumDp[max(0LL, i - L[j])] - sumDp[max(0LL, i - R[j] - 1)] + MOD) % MOD) %= MOD;
    (sumDp[i] = sumDp[i - 1] + dp[i]) %= MOD;
  }
  cout << dp[N] << endl;
  return 0;
}
