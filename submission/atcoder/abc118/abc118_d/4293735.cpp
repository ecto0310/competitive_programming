// URL: https://atcoder.jp/contests/abc118/submissions/4293735
// Date: Sat, 16 Feb 2019 23:51:31 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int cnt[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> A(M);
  for (int i = 0; i < M; i++)
    cin >> A[i];
  vector<string> dp(N + 1, "");
  for (int i = 0; i < N; i++)
    for (int j : A)
      if (i + cnt[j] <= N)
      {
        if (i != 0 && dp[i] == "")
          continue;
        if (dp[i + cnt[j]].size() < dp[i].size() + 1)
          dp[i + cnt[j]] = to_string(j) + dp[i];
        else if (dp[i + cnt[j]].size() == dp[i].size() + 1 && dp[i + cnt[j]] < to_string(j) + dp[i])
          dp[i + cnt[j]] = to_string(j) + dp[i];
      }
  cout << dp[N] << endl;

  return 0;
}
