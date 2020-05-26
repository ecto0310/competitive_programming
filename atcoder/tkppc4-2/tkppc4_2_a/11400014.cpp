// URL: https://atcoder.jp/contests/tkppc4-2/submissions/11400014
// Date: Wed, 01 Apr 2020 00:44:06 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 X, Y;
  cin >> X >> Y;
  if (Y < 0 || Y % 2 == 1)
  {
    cout << -1 << endl;
    return 0;
  }
  if (Y / 2 < abs(X) || (Y / 2 - abs(X)) % 2 == 1)
    cout << -1 << endl;
  else
    cout << Y / 2 << endl;
  return 0;
}
