// URL: https://atcoder.jp/contests/joi2007ho/submissions/8831399
// Date: Sun, 08 Dec 2019 10:43:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  vector<i64> sum(n + 1);
  for (i64 i = 0; i < n; i++)
    sum[i + 1] = sum[i] + a[i];
  i64 ans = -1e9;
  for (i64 i = 0; i < n - k; i++)
    ans = max(ans, sum[i + k] - sum[i]);
  cout << ans << endl;
  return 0;
}
