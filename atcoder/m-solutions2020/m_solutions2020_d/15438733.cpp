// URL: https://atcoder.jp/contests/m-solutions2020/submissions/15438733
// Date: Sat, 25 Jul 2020 21:47:50 +0900
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
  i64 ans = 1000, ka = 0;
  for (i64 i = 0; i < N; i++)
    if (i + 1 == N || A[i + 1] < A[i])
    {
      ans += ka * A[i];
      ka = 0;
    }
    else if (A[i] < A[i + 1])
    {
      ka += ans / A[i];
      ans -= ans / A[i] * A[i];
    }
  cout << ans << endl;
  return 0;
}
