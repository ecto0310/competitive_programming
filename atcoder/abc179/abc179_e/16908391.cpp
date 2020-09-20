// URL: https://atcoder.jp/contests/abc179/submissions/16908391
// Date: Sun, 20 Sep 2020 17:24:30 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, X, M;
  cin >> N >> X >> M;
  vector<i64> A(M + 2), sum(M + 2), ind(M + 1, -1);
  A[1] = X;
  sum[1] = X;
  ind[X] = 1;
  i64 loopStart, loopSize;
  for (i64 i = 2; i <= M + 1; i++)
  {
    A[i] = (A[i - 1] * A[i - 1]) % M;
    sum[i] = sum[i - 1] + A[i];
    if (i == N)
    {
      cout << sum[i] << endl;
      return 0;
    }
    if (ind[A[i]] != -1)
    {
      loopStart = ind[A[i]];
      loopSize = i - ind[A[i]];
      break;
    }
    ind[A[i]] = i;
  }
  i64 ans = 0;
  i64 loopCnt = (N - loopStart) / loopSize;
  ans += loopCnt * (sum[loopSize + loopStart] - sum[loopStart]);
  N -= loopSize * loopCnt;
  ans += sum[N];
  cout << ans << endl;
  return 0;
}
