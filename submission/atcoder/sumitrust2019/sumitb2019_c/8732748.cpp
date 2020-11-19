// URL: https://atcoder.jp/contests/sumitrust2019/submissions/8732748
// Date: Sun, 01 Dec 2019 21:19:14 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 x;
  cin >> x;
  if (x / 100 * 5 < x % 100)
    cout << 0 << endl;
  else
    cout << 1 << endl;
  return 0;
}
