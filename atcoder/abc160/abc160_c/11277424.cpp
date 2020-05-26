// URL: https://atcoder.jp/contests/abc160/submissions/11277424
// Date: Sat, 28 Mar 2020 21:06:58 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 K, N;
  cin >> K >> N;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  i64 ans = K - (A[N - 1] - A[0]);
  for (i64 i = 0; i < N - 1; i++)
    ans = max(ans, A[i + 1] - A[i]);
  cout << K - ans << endl;
  return 0;
}
