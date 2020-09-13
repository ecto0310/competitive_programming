// URL: https://atcoder.jp/contests/abc178/submissions/16724462
// Date: Sun, 13 Sep 2020 23:08:39 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max({a * c, a * d, b * c, b * d}) << endl;
  return 0;
}
