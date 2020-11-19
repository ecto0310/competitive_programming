// URL: https://atcoder.jp/contests/joi2007ho/submissions/6865202
// Date: Mon, 12 Aug 2019 17:24:21 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
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
  for (i64 i = 1; i < n + 1; i++)
    sum[i] = sum[i - 1] + a[i];
  i64 ans = 0;
  for (i64 i = 0; i < n - k; i++)
    ans = max(ans, sum[i + k] - sum[i]);
  cout << ans << endl;
  return 0;
}
