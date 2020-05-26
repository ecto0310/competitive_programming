// URL: https://atcoder.jp/contests/joi2018ho/submissions/4010172
// Date: Mon, 14 Jan 2019 00:21:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<long long> T(N), w(N - 1);
  for (int i = 0; i < N; i++)
  {
    cin >> T[i];
    if (i != 0)
      w[i - 1] = max(0LL, T[i] - T[i - 1] - 1);
  }
  sort(w.begin(), w.end(), greater<long long>());
  long long ans = T[N - 1] + 1 - T[0];
  for (int i = 0; i < K - 1; i++)
    ans -= w[i];
  cout << ans << endl;

  return 0;
}
