// URL: https://atcoder.jp/contests/ddcc2020-qual/submissions/10484561
// Date: Mon, 02 Mar 2020 15:09:03 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 X, Y;
  cin >> X >> Y;
  i64 ans = 0;
  if (X == 3)
    ans += 100000;
  else if (X == 2)
    ans += 200000;
  else if (X == 1)
    ans += 300000;
  if (Y == 3)
    ans += 100000;
  else if (Y == 2)
    ans += 200000;
  else if (Y == 1)
    ans += 300000;
  if (X == 1 && Y == 1)
    ans += 400000;
  cout << ans << endl;
  return 0;
}
