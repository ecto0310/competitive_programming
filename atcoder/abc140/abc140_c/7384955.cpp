// URL: https://atcoder.jp/contests/abc140/submissions/7384955
// Date: Sat, 07 Sep 2019 21:07:22 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> b(n - 1);
  for (i64 i = 0; i < n - 1; i++)
    cin >> b[i];
  i64 ans = b[0] + b[n - 2];
  for (i64 i = 0; i < n - 2; i++)
    ans += min(b[i], b[i + 1]);
  cout << ans << endl;
  return 0;
}
