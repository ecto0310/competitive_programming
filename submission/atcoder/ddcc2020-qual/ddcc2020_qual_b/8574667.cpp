// URL: https://atcoder.jp/contests/ddcc2020-qual/submissions/8574667
// Date: Sat, 23 Nov 2019 21:11:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  vector<i64> sum(n + 1);
  for (i64 i = 0; i < n; i++)
    sum[i + 1] = sum[i] + a[i];
  i64 ans = 1e18;
  for (i64 i = 0; i < n; i++)
    ans = min(ans, abs(sum[i] - (sum[n] - sum[i])));
  cout << ans << endl;
  return 0;
}
