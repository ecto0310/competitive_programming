// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3860121
// Date: Wed, 11 Sep 2019 16:24:09 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 x, y;
  cin >> x >> y;
  cout << x + y - __gcd(x, y) + 1 << endl;
  return 0;
}
