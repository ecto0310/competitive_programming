// URL: https://codeforces.com/contest/1337/submission/76820819
// Date: Wed, 15 Apr 2020 23:46:02 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 t;
  cin >> t;
  for (i64 _ = 0; _ < t; _++)
  {
    i64 x, n, m;
    cin >> x >> n >> m;
    if (x / 2 + 10 < x)
      for (i64 i = 0; i < n; i++)
        if (x / 2 + 10 < x)
          x = x / 2 + 10;
    for (i64 i = 0; i < m; i++)
      x -= 10;
    if (0 < x)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
