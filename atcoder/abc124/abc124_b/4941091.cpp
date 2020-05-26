// URL: https://atcoder.jp/contests/abc124/submissions/4941091
// Date: Sat, 13 Apr 2019 21:04:41 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> h(n);
  for (i64 i = 0; i < n; i++)
    cin >> h[i];
  i64 ans = 0, now = 0;
  for (i64 i = 0; i < n; i++)
  {
    if (now <= h[i])
      ans++;
    now = max(now, h[i]);
  }
  cout << ans << endl;

  return 0;
}
