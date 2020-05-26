// URL: https://atcoder.jp/contests/panasonic2020/submissions/10871413
// Date: Sat, 14 Mar 2020 21:57:22 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 H, W;
  cin >> H >> W;
  if (H == 1 || W == 1)
    cout << 1 << endl;
  else
    cout << ((H + 1) / 2) * ((W + 1) / 2) + (H / 2) * (W / 2) << endl;
  return 0;
}
