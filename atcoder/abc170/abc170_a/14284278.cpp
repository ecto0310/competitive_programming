// URL: https://atcoder.jp/contests/abc170/submissions/14284278
// Date: Sun, 14 Jun 2020 21:01:05 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  for (i64 i = 0; i < 5; i++)
  {
    i64 x;
    cin >> x;
    if (x == 0)
    {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
