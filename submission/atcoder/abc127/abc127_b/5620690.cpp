// URL: https://atcoder.jp/contests/abc127/submissions/5620690
// Date: Sun, 26 May 2019 00:17:51 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 r, d, x;
  cin >> r >> d >> x;
  for (i64 i = 0; i < 10; i++)
  {
    x = r * x - d;
    cout << x << endl;
  }
  return 0;
}
