// URL: https://atcoder.jp/contests/abc174/submissions/15593371
// Date: Sun, 02 Aug 2020 21:01:48 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, D;
  cin >> N >> D;
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
  {
    i64 X, Y;
    cin >> X >> Y;
    if (X * X + Y * Y <= D * D)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
