// URL: https://atcoder.jp/contests/arc004/submissions/11551217
// Date: Sat, 04 Apr 2020 23:23:28 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> x(N), y(N);
  for (i64 i = 0; i < N; i++)
    cin >> x[i] >> y[i];
  double ans = 0;
  for (i64 i = 0; i < N; i++)
    for (i64 j = 0; j < N; j++)
      ans = max(ans, hypot(x[i] - x[j], y[i] - y[j]));
  cout << fixed << setprecision(4) << ans << endl;
  return 0;
}
