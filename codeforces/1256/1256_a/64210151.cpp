// URL: https://codeforces.com/contest/1256/submission/64210151
// Date: Mon, 04 Nov 2019 22:20:34 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 q;
  cin >> q;
  for (i64 _ = 0; _ < q; _++)
  {
    i64 a, b, n, s;
    cin >> a >> b >> n >> s;
    s -= min(a, s / n) * n;
    if (s <= b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
