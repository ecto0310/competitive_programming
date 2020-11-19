// URL: https://atcoder.jp/contests/abc040/submissions/4247771
// Date: Wed, 13 Feb 2019 01:18:56 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  vector<long long> dp(N, 1e9);
  dp[0] = 0;
  for (int i = 0; i < N; i++)
  {
    if (i + 1 < N)
      dp[i + 1] = min(dp[i + 1], dp[i] + abs(a[i] - a[i + 1]));
    if (i + 2 < N)
      dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i] - a[i + 2]));
  }
  cout << dp[N - 1] << endl;

  return 0;
}
