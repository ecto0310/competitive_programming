// URL: https://codeforces.com/contest/1305/submission/72314114
// Date: Tue, 03 Mar 2020 23:39:47 +0900
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
    i64 n;
    cin >> n;
    vector<i64> a(n), b(n);
    for (i64 i = 0; i < n; i++)
      cin >> a[i];
    for (i64 i = 0; i < n; i++)
      cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (i64 i = 0; i < n; i++)
      cout << a[i] << " \n"[i + 1 == n];
    for (i64 i = 0; i < n; i++)
      cout << b[i] << " \n"[i + 1 == n];
  }
  return 0;
}
