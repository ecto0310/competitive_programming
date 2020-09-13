// URL: https://atcoder.jp/contests/abc178/submissions/16727169
// Date: Sun, 13 Sep 2020 23:54:55 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 MOD = 1e9 + 7;

int main()
{
  i64 S;
  cin >> S;
  vector<i64> dp(S+1);
  dp[0] = 1;
  for (i64 i = 1; i <= S; i++)
    for (i64 j = 0; j <= i - 3; j++)
      (dp[i] += dp[j]) %= MOD;
  cout << dp[S] << endl;
  return 0;
}
