// URL: https://atcoder.jp/contests/abc185/submissions/18766324
// Date: Sun, 13 Dec 2020 23:17:17 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<i64> A(N), B(M);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  for (i64 i = 0; i < M; i++)
    cin >> B[i];
  vector<vector<i64>> dp(N + 1, vector<i64>(M + 1));
  for (i64 i = 0; i <= N; i++)
    dp[i][0] = i;
  for (i64 i = 0; i <= M; i++)
    dp[0][i] = i;
  for (i64 i = 1; i <= N; i++)
    for (i64 j = 1; j <= M; j++)
    {
      i64 m = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
      if (A[i - 1] == B[j - 1])
      {
        m = min(m, dp[i - 1][j - 1]);
        dp[i][j] = m;
      }
      else
      {
        m = min(m, dp[i - 1][j - 1] + 1);
        dp[i][j] = m;
      }
    }
  cout << dp[N][M] << endl;
  return 0;
}
