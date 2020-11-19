// URL: https://atcoder.jp/contests/m-solutions2020/submissions/15414158
// Date: Sat, 25 Jul 2020 21:03:08 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 X;
  cin >> X;
  for (i64 i = 0;; i++)
    if (1800 - 200 * i <= X)
    {
      cout << i + 1 << endl;
      return 0;
    }
  return 0;
}
