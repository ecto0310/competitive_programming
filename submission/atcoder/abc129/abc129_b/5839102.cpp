// URL: https://atcoder.jp/contests/abc129/submissions/5839102
// Date: Sun, 09 Jun 2019 21:07:22 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> w(n);
  for (i64 i = 0; i < n; i++)
    cin >> w[i];
  i64 ans = 1e9;
  for (i64 i = 0; i < n; i++)
  {
    i64 small = 0, big = 0;
    for (i64 j = 0; j < n; j++)
      if (i < j)
        big += w[j];
      else
        small += w[j];
    ans = min(ans, abs(big - small));
  }
  cout << ans << endl;
  return 0;
}
