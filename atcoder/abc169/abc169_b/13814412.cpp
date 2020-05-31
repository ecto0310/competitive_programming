// URL: https://atcoder.jp/contests/abc169/submissions/13814412
// Date: Sun, 31 May 2020 21:19:19 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  sort(A.begin(), A.end());
  i64 ans = A[0];
  for (i64 i = 1; i < N; i++)
  {
    if (ans != 0 && (i64)1e18 / ans < A[i])
    {
      cout << -1 << endl;
      return 0;
    }
    ans *= A[i];
  }
  cout << ans << endl;
  return 0;
}
