// URL: https://atcoder.jp/contests/abc113/submissions/3901467
// Date: Sun, 30 Dec 2018 22:31:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<int>> dp(H + 1, vector<int>(W, 0));
  dp[0][0] = 1;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      for (int bit = 0; bit < 1 << (W - 1); bit++)
      {
        cerr << bit << " " << 1 << (W - 1) << endl;
        bool ok = true;
        for (int k = 0; k < W - 2; k++)
          if (bit & (1 << k) && bit & (1 << (k + 1)))
            ok = false;
        if (!ok)
          continue;
        if (0 < j && (bit & (1 << (j - 1))))
        {
          dp[i + 1][j - 1] += dp[i][j];
          dp[i + 1][j - 1] %= mod;
        }
        else if (j < W - 1 && (bit & (1 << j)))
        {
          dp[i + 1][j + 1] += dp[i][j];
          dp[i + 1][j + 1] %= mod;
        }
        else
        {
          dp[i + 1][j] += dp[i][j];
          dp[i + 1][j] %= mod;
        }
      }
  cout << dp[H][K - 1] << endl;

  return 0;
}
