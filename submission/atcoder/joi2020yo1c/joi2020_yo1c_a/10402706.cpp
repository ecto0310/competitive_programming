// URL: https://atcoder.jp/contests/joi2020yo1c/submissions/10402706
// Date: Sat, 29 Feb 2020 17:44:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 x, l, r;
  cin >> x >> l >> r;
  if (l <= x && x <= r)
    cout << x << endl;
  else if (x < l)
    cout << l << endl;
  else
    cout << r << endl;
  return 0;
}
