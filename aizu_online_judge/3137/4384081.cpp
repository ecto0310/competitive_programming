// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4384081
// Date: Tue, 21 Apr 2020 23:04:36 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 a, b, c, d;
  cin >> a >> b >> c >> d;
  i64 t = a + b + c + d;
  cout << abs(t - max({a, b, c, d}) - min({a, b, c, d}) - (max({a, b, c, d}) + min({a, b, c, d}))) << endl;
  return 0;
}
