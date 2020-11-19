// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3558606
// Date: Sat, 11 May 2019 14:43:13 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;
const i64 MOD = 1e9 + 7;

int main()
{
  i64 n;
  string s, t;
  cin >> n >> s >> t;
  i64 dp[26] = {};
  dp[s[0] - 'a'] = 1;
  for (i64 i = 1; i < n - 1; i++)
    (dp[s[i] - 'a'] += dp[t[i] - 'a']) %= MOD;
  cout << dp[t[n - 1] - 'a'] % MOD << endl;
  return 0;
}
