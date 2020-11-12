// URL: https://atcoder.jp/contests/abc180/submissions/18063771
// Date: Thu, 12 Nov 2020 20:26:27 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> x(N);
  for (i64 i = 0; i < N; i++)
    cin >> x[i];
  i64 ans1 = 0;
  for (i64 i = 0; i < N; i++)
    ans1 += abs(x[i]);
  cout << ans1 << endl;
  i64 ans2 = 0;
  for (i64 i = 0; i < N; i++)
    ans2 += x[i] * x[i];
  cout << fixed << setprecision(10) << sqrt((long double)ans2) << endl;
  i64 ans3 = 0;
  for (i64 i = 0; i < N; i++)
    ans3 = max(ans3, abs(x[i]));
  cout << ans3 << endl;
  return 0;
}
