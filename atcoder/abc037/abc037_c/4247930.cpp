// URL: https://atcoder.jp/contests/abc037/submissions/4247930
// Date: Wed, 13 Feb 2019 01:54:10 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];
  vector<long long> sum(N + 1, 0);
  for (int i = 0; i < N; i++)
    sum[i + 1] = sum[i] + a[i];
  long long ans = 0;
  for (int i = K; i <= N; i++)
    ans += sum[i] - sum[i - K];
  cout << ans << endl;

  return 0;
}
