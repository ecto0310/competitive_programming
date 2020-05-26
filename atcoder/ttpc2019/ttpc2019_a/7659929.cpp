// URL: https://atcoder.jp/contests/ttpc2019/submissions/7659929
// Date: Mon, 23 Sep 2019 00:52:44 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, t;
  cin >> a >> b >> t;
  cout << (t - b + (b - a) - 1) / (b - a) * (b - a) + b << endl;
  return 0;
}
