// URL: https://atcoder.jp/contests/abc104/submissions/3917923
// Date: Wed, 02 Jan 2019 23:11:03 +0900
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
    for (int j = 0; j < 4; j++)
    {
      dp[i + 1][j] += dp[i][j] * (s[i] == '?' ? 3 : 1);
      if (j < 3 && (s[i] == '?' || s[i] == "ABC"[j]))
        dp[i + 1][j + 1] += dp[i][j];
      dp[i + 1][j] %= mod;
      dp[i + 1][j + 1] %= mod;
    }
  cout << dp[size][3] % mod << endl;

  return 0;
}
