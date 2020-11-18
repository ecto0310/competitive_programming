// URL: https://atcoder.jp/contests/joi2021yo1b/submissions/18212447
// Date: Thu, 19 Nov 2020 07:42:52 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"
 
int main()
{
  i64 A, B, C;
  cin >> A >> B >> C;
  if (A <= C && C < B)
    cout << 1 << endl;
  else
    cout << 0 << endl;
  return 0;
}
