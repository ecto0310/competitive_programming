// URL: https://atcoder.jp/contests/abc170/submissions/14288256
// Date: Sun, 14 Jun 2020 21:02:21 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 X, Y;
  cin >> X >> Y;
  for (i64 i = 0; i <= X; i++)
  {
    if (i * 2 + (X - i) * 4 == Y)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
