// URL: https://atcoder.jp/contests/abc133/submissions/10484815
// Date: Mon, 02 Mar 2020 15:22:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
    ans = A[i] * 2 - ans;
  ans /= 2;
  for (i64 i = 0; i < N; i++)
  {
    cout << ans << " \n"[i + 1 == N];
    ans = A[i] * 2 - ans;
  }
  return 0;
}
