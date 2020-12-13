// URL: https://atcoder.jp/contests/abc185/submissions/18765752
// Date: Sun, 13 Dec 2020 23:06:47 +0900
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
  dp[0][0] = 0;
  for (i64 i = 1; i <= N; i++)
    dp[i][0] = i;
  for (i64 i = 1; i <= M; i++)
    dp[0][i] = i;
  for (i64 i = 1; i <= N; i++)
    for (i64 j = 1; j <= M; j++)
    {
      i64 D = dp[i - 1][j] + 1;
      i64 I = dp[i][j - 1] + 1;
      i64 C = dp[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 0 : 1);
      dp[i][j] = min({D, I, C});
    }
  cout << dp[N][M] << endl;
  return 0;
}
