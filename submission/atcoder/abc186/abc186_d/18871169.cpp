// URL: https://atcoder.jp/contests/abc186/submissions/18871169
// Date: Sat, 19 Dec 2020 21:10:42 +0900
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
  sort(A.rbegin(), A.rend());
  i64 ans = 0;
  vector<i64> sum = A;
  for (i64 i = 1; i < N; i++)
    sum[i] += sum[i - 1];
  for (i64 i = 0; i < N; i++)
  {
    ans += A[i] * (N - i - 1);
    ans -= sum[N - 1] - sum[i];
  }
  cout << ans << endl;
  return 0;
}
