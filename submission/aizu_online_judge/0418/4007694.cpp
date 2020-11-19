// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4007694
// Date: Mon, 25 Nov 2019 23:21:53 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 x1, y1, w1, h1, x2, y2, w2, h2;
  cin >> x1 >> y1 >> w1 >> h1 >> x2 >> y2 >> w2 >> h2;
  if (x1 + w1 <= x2 || x2 + w2 <= x1 || y1 + h1 <= y2 || y2 + h2 <= y1)
    cout << h1 * w1 + h2 * w2 << endl;
  else
  {
    i64 hh, ww;
    if (x1 < x2 && x2 + w2 < x1 + w1)
      ww = w2;
    else if (x2 < x1 && x1 + w1 < x2 + w2)
      ww = w1;
    else if (x1 < x2)
      ww = x1 + w1 - x2;
    else
      ww = x2 + w2 - x1;
    if (y1 < y2 && y2 + h2 < y1 + h1)
      hh = h2;
    else if (y2 < y1 && y1 + h1 < y2 + h2)
      hh = h1;
    else if (y1 < y2)
      hh = y1 + h1 - y2;
    else
      hh = y2 + h2 - y1;
    cout << h1 * w1 + h2 * w2 - hh * ww * 2 << endl;
  }
  return 0;
}
