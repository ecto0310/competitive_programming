// URL: https://atcoder.jp/contests/abc172/submissions/14742225
// Date: Sat, 27 Jun 2020 21:15:44 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M, K;
  cin >> N >> M >> K;
  vector<i64> A(N), B(M);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  for (i64 i = 0; i < M; i++)
    cin >> B[i];
  for (i64 i = 0; i < N - 1; i++)
    A[i + 1] += A[i];
  for (i64 i = 0; i < M - 1; i++)
    B[i + 1] += B[i];
  i64 ans = 0;
  i64 l = M;
  for (i64 i = 0; i <= N; i++)
    for (i64 j = l; 0 <= j; j--)
    {
      i64 t = 0;
      if (i != 0)
        t += A[i - 1];
      if (j != 0)
        t += B[j - 1];
      if (t <= K)
      {
        ans = max(ans, i + j);
        break;
      }
      else
        l = j;
    }
  cout << ans << endl;
  return 0;
}
