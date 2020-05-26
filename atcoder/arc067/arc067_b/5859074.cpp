// URL: https://atcoder.jp/contests/arc067/submissions/5859074
// Date: Sun, 09 Jun 2019 23:32:53 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, a, b;
  cin >> n >> a >> b;
  vector<i64> x(n);
  for (i64 i = 0; i < n; i++)
    cin >> x[i];
  i64 ans = 0;
  for (i64 i = 0; i < n - 1; i++)
    ans += min(a * (x[i + 1] - x[i]), b);
  cout << ans << endl;
  return 0;
}
