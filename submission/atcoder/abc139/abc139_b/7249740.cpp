// URL: https://atcoder.jp/contests/abc139/submissions/7249740
// Date: Sun, 01 Sep 2019 21:04:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b;
  cin >> a >> b;
  i64 tap = 1;
  for (i64 i = 0;; i++)
  {
    if (b <= tap)
    {
      cout << i << endl;
      return 0;
    }
    tap += a - 1;
  }
  return 0;
}
