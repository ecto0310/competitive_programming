// URL: https://atcoder.jp/contests/abc185/submissions/18739892
// Date: Sun, 13 Dec 2020 21:29:30 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 L;
  cin >> L;
  vector<vector<i64>> dp(L + 1, vector<i64>(13));
  dp[0][0] = 1;
  for (i64 i = 0; i <= L; i++)
    for (i64 j = 1; j <= 12; j++)
    {
      i64 sum = 0;
      for (i64 k = 0; k < i; k++)
        sum += dp[k][j - 1];
      dp[i][j] += sum;
      cerr << i << " " << j << " " << dp[i][j] << endl;
    }
  cout << dp[L][12] << endl;
  return 0;
}
