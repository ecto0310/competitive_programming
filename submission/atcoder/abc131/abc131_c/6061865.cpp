// URL: https://atcoder.jp/contests/abc131/submissions/6061865
// Date: Sat, 22 Jun 2019 21:19:58 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

i64 lcm(i64 i, i64 j)
{
  return i * j / __gcd(i, j);
}

int main()
{
  i64 a, b, c, d;
  cin >> a >> b >> c >> d;
  a--;
  cout << b - a - ((b / c + b / d - b / lcm(c, d)) - (a / c + a / d - a / lcm(c, d))) << endl;
  return 0;
}
