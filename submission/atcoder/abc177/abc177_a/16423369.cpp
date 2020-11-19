// URL: https://atcoder.jp/contests/abc177/submissions/16423369
// Date: Mon, 31 Aug 2020 19:35:26 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 D, T, S;
  cin >> D >> T >> S;
  if (T * S < D)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
  return 0;
}
