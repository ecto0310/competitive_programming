// URL: https://atcoder.jp/contests/tkppc3/submissions/6546400
// Date: Fri, 26 Jul 2019 23:45:52 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  string c1, c2;
  i64 a, b;
  cin >> c1 >> a >> c2 >> b;
  if (c1 == c2)
    cout << abs(b - a) / 15 << endl;
  else
    cout << (a + b) / 15 << endl;
  return 0;
}
