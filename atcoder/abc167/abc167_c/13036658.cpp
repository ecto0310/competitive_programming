// URL: https://atcoder.jp/contests/abc167/submissions/13036658
// Date: Sun, 10 May 2020 21:09:23 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M, X;
  cin >> N >> M >> X;
  vector<i64> C(N);
  vector<vector<i64>> A(N, vector<i64>(M));
  for (i64 i = 0; i < N; i++)
  {
    cin >> C[i];
    for (i64 j = 0; j < M; j++)
      cin >> A[i][j];
  }
  i64 ans = 1e9;
  for (i64 i = 0; i < (1 << N); i++)
  {
    i64 sum = 0;
    vector<i64> s(M);
    for (i64 j = 0; j < N; j++)
      if (i & (1 << j))
      {
        sum += C[j];
        for (i64 k = 0; k < M; k++)
          s[k] += A[j][k];
      }
    bool ok = true;
    for (i64 j = 0; j < M; j++)
      if (s[j] < X)
        ok = false;
    if (ok)
      ans = min(ans, sum);
  }
  if (ans == 1e9)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
