// URL: https://atcoder.jp/contests/abc156/submissions/10268551
// Date: Sat, 22 Feb 2020 21:04:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N;
  cin >> N;
  vector<i64> X(N);
  for (i64 i = 0; i < N; i++)
    cin >> X[i];
  i64 ans = 1e9;
  for (i64 i = 0; i <= 100; i++)
  {
    i64 tmp = 0;
    for (i64 j = 0; j < N; j++)
      tmp += (i - X[j]) * (i - X[j]);
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
