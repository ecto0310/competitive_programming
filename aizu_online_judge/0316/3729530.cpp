// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3729530
// Date: Tue, 09 Jul 2019 15:40:07 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 h1, h2, k1, k2, a, b, c, d;
  cin >> h1 >> h2 >> k1 >> k2 >> a >> b >> c >> d;
  i64 hi = h1 * a + (h1 / 10) * c + h2 * b + (h2 / 20) * d, ke = k1 * a + (k1 / 10) * c + k2 * b + (k2 / 20) * d;
  if (ke < hi)
    cout << "hiroshi" << endl;
  else if (hi < ke)
    cout << "kenjiro" << endl;
  else
    cout << "even" << endl;
  return 0;
}
