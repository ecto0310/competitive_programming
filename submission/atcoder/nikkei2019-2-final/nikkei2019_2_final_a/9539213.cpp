// URL: https://atcoder.jp/contests/nikkei2019-2-final/submissions/9539213
// Date: Fri, 17 Jan 2020 01:22:35 +0900
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
  {
    i64 l = 0, r = 0;
    for (i64 j = 0; j < i; j++)
      if (a[j] < a[i])
        l++;
    for (i64 j = i + 1; j < n; j++)
      if (a[j] < a[i])
        r++;
    ans += l * r;
  }
  cout << ans << endl;
  return 0;
}
