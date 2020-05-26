// URL: https://atcoder.jp/contests/chokudai_S001/submissions/9539159
// Date: Fri, 17 Jan 2020 01:17:55 +0900
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
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    ans += a[i];
  cout << ans << endl;
  return 0;
}
