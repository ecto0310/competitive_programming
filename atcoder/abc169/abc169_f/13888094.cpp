// URL: https://atcoder.jp/contests/abc169/submissions/13888094
// Date: Sun, 31 May 2020 23:00:53 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const i64 MOD = 998244353;

int main()
{
  i64 N, S;
  cin >> N >> S;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  vector<vector<i64>> dp(N + 1, vector<i64>(S + 1));
  dp[0][0] = 1;
  for (i64 i = 0; i < N; i++)
  {
    for (i64 j = 0; j <= S; j++)
      (dp[i + 1][j] = dp[i][j] * 2) %= MOD;
    for (i64 j = 0; j <= S - A[i]; j++)
      (dp[i + 1][j + A[i]] += dp[i][j]) %= MOD;
  }
  cout << dp[N][S] << endl;
  return 0;
}
