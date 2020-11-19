// URL: https://atcoder.jp/contests/agc011/submissions/4012098
// Date: Mon, 14 Jan 2019 11:04:47 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, C, K;
  cin >> N >> C >> K;
  vector<int> T(N);
  for (int i = 0; i < N; i++)
    cin >> T[i];
  sort(T.begin(), T.end());
  int ans = 1, ride = 1, ti = T[0] + K;
  for (int i = 1; i < N; i++)
    if (ride == C || ti < T[i])
    {
      ans++;
      ride = 1;
      ti = T[i] + K;
    }
    else
    {
      ride++;
    }
  cout << ans << endl;

  return 0;
}
