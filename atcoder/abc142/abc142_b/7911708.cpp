// URL: https://atcoder.jp/contests/abc142/submissions/7911708
// Date: Wed, 09 Oct 2019 01:06:30 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<i64> h(n);
  for (i64 i = 0; i < n; i++)
    cin >> h[i];
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    if (k <= h[i])
      ans++;
  cout << ans << endl;
  return 0;
}
