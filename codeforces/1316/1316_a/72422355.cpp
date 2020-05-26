// URL: https://codeforces.com/contest/1316/submission/72422355
// Date: Wed, 04 Mar 2020 23:37:22 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 t;
  cin >> t;
  for (i64 _ = 0; _ < t; _++)
  {
    i64 n, m;
    cin >> n >> m;
    vector<i64> a(n);
    for (i64 i = 0; i < n; i++)
      cin >> a[i];
    i64 ans = 0;
    for (i64 i = 0; i < n; i++)
      ans += a[i];
    cout << min(m, ans) << "\n";
  }
  return 0;
}
