// URL: https://atcoder.jp/contests/abc138/submissions/10484472
// Date: Mon, 02 Mar 2020 15:04:52 +0900
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
  double ans = 0;
  for (i64 i = 0; i < N; i++)
    ans += 1.0 / A[i];
  cout << fixed << setprecision(6) << 1.0 / ans << endl;
  return 0;
}
