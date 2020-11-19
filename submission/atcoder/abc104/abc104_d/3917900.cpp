// URL: https://atcoder.jp/contests/abc104/submissions/3917900
// Date: Wed, 02 Jan 2019 23:08:58 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
  string s;
  cin >> s;
  int size = s.size();
  vector<vector<long long>> dp(size + 1, vector<long long>(4, 0));
  dp[0][0] = 1;
  for (int i = 0; i < size; i++)
  {
    if (s[i] == 'A' || s[i] == '?')
      dp[i + 1][1] += (dp[i + 1][1] + dp[i][0]) % mod;
    if (s[i] == 'B' || s[i] == '?')
      dp[i + 1][2] += (dp[i + 1][2] + dp[i][1]) % mod;
    if (s[i] == 'C' || s[i] == '?')
      dp[i + 1][3] += (dp[i + 1][3] + dp[i][2]) % mod;
    for (int j = 0; j < 4; j++)
      dp[i + 1][j] += dp[i][j] * (s[i] == '?' ? 3 : 1) % mod;
  }
  cout << dp[size][3] % mod << endl;

  return 0;
}
