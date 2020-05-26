// URL: https://atcoder.jp/contests/joi2015yo/submissions/8709218
// Date: Sat, 30 Nov 2019 20:13:15 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, c, d, p;
  cin >> a >> b >> c >> d >> p;
  cout << min(a * p, b + max(0LL, p - c) * d) << endl;
  return 0;
}
