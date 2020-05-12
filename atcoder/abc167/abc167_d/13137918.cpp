// URL: https://atcoder.jp/contests/abc167/submissions/13137918
// Date: Tue, 12 May 2020 00:31:29 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "
"

int main()
{
  i64 N, K;
  cin >> N >> K;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
  {
    cin >> A[i];
    A[i]--;
  }
  vector<vector<i64>> to(60, vector<i64>(N));
  for (i64 i = 0; i < N; i++)
    to[0][i] = A[i];
  for (i64 i = 0; i < 59; i++)
    for (i64 j = 0; j < N; j++)
      to[i + 1][j] = to[i][to[i][j]];
  i64 ans = 0;
  for (i64 i = 0; i < 60; i++)
    if (K & (1LL << i))
      ans = to[i][ans];
  cout << ans + 1 << endl;
  return 0;
}
