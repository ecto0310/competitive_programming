// URL: https://atcoder.jp/contests/abc176/submissions/16175183
// Date: Sun, 23 Aug 2020 16:13:07 +0900
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
  i64 ans = 0, m = A[0];
  for (i64 i = 1; i < N; i++)
  {
    ans += max(0LL, m - A[i]);
    m = max(m, A[i]);
  }
  cout << ans << endl;
  return 0;
}
