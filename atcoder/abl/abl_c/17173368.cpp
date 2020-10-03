// URL: https://atcoder.jp/contests/abl/submissions/17173368
// Date: Sat, 03 Oct 2020 22:38:25 +0900
// Language: C++ (GCC 9.2.1 with AC Library v1.1)
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<i64> A(M), B(M);
  for (i64 i = 0; i < M; i++)
  {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }
  dsu b(N);
  i64 ans = N - 1;
  for (i64 i = 0; i < M; i++)
    if (!b.same(A[i], B[i]))
    {
      b.merge(A[i], B[i]);
      ans--;
    }
  cout << ans << endl;
  return 0;
}
