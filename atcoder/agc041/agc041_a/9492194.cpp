// URL: https://atcoder.jp/contests/agc041/submissions/9492194
// Date: Mon, 13 Jan 2020 15:25:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, a, b;
  cin >> n >> a >> b;
  if (a % 2 == b % 2)
    cout << (b - a) / 2 << endl;
  else
    cout << min(a - 1, n - b) + 1 + (b - a - 1) / 2 << endl;
  return 0;
}
