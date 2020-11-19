// URL: https://atcoder.jp/contests/joi2020yo1b/submissions/10402687
// Date: Sat, 29 Feb 2020 17:43:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, c;
  cin >> a >> b >> c;
  cout << a + b + c - min({a, b, c}) << endl;
}
