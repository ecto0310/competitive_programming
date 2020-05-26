// URL: https://atcoder.jp/contests/abc164/submissions/12345988
// Date: Sun, 26 Apr 2020 21:05:16 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 S, W;
  cin >> S >> W;
  if (W < S)
    cout << "safe" << endl;
  else
    cout << "unsafe" << endl;
  return 0;
}
