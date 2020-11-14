// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4992070
// Date: Sat, 14 Nov 2020 22:11:11 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 w, m, s;
  cin >> w >> m >> s;
  i64 t = w - s;
  if (s <= m && t <= m)
    cout << 3 << endl;
  else if (s <= m)
    cout << 1 << endl;
  else if (t <= m)
    cout << 2 << endl;
  else
    cout << 0 << endl;
  return 0;
}
