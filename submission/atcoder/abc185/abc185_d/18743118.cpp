// URL: https://atcoder.jp/contests/abc185/submissions/18743118
// Date: Sun, 13 Dec 2020 21:37:08 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<i64> A(M + 2);
  for (i64 i = 0; i < M; i++)
    cin >> A[i + 1];
  A[0] = 0;
  A[M + 1] = N + 1;
  i64 size = 1e9;
  sort(A.begin(), A.end());
  for (i64 i = 0; i < M + 1; i++)
    if (A[i + 1] - A[i] != 1)
      size = min(size, A[i + 1] - A[i] - 1);
  i64 ans = 0;
  for (i64 i = 0; i < M + 1; i++)
    ans += (A[i + 1] - A[i] - 1 + size - 1) / size;
  cout << ans << endl;
  return 0;
}
