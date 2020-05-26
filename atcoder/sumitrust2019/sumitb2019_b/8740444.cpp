// URL: https://atcoder.jp/contests/sumitrust2019/submissions/8740444
// Date: Sun, 01 Dec 2019 21:51:55 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  for (i64 i = 0; i <= 50000; i++)
    if ((i64)(i * 1.08) == n)
    {
      cout << i << endl;
      return 0;
    }
  cout << ":(" << endl;
  return 0;
}
