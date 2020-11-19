// URL: https://atcoder.jp/contests/abc170/submissions/14358922
// Date: Sun, 14 Jun 2020 22:45:41 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(1000001);
  for (i64 i = 0; i < N; i++)
  {
    i64 a;
    cin >> a;
    A[a]++;
  }
  i64 ans = 0;
  for (i64 i = 0; i < 1000001; i++)
  {
    if (A[i] == 0)
      continue;
    if (A[i] == 1)
      ans++;
    for (i64 j = i * 2; j < 1000001; j += i)
      A[j] = 0;
  }
  cout << ans << endl;
  return 0;
}
