// URL: https://atcoder.jp/contests/abc175/submissions/15926427
// Date: Sat, 15 Aug 2020 21:23:18 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 X, K, D;
  cin >> X >> K >> D;
  if (K < abs(X) / D)
    cout << abs(X + (0 <= X ? -1 : 1) * K * D) << endl;
  else
  {
    K -= abs(X) / D;
    if (K % 2 == 0)
      cout << abs(X + (0 <= X ? -1 : 1) * (abs(X) / D) * D) << endl;
    else
      cout << abs(X + (0 <= X ? -1 : 1) * (abs(X) / D + 1) * D) << endl;
  }
  return 0;
}
