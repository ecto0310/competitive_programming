// URL: https://atcoder.jp/contests/abc148/submissions/9060965
// Date: Sun, 22 Dec 2019 21:04:59 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b;
  cin >> a >> b;
  cout << a / __gcd(a, b) * b << endl;
  return 0;
}
