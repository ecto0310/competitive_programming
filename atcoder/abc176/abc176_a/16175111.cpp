// URL: https://atcoder.jp/contests/abc176/submissions/16175111
// Date: Sun, 23 Aug 2020 16:10:09 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, X, T;
  cin >> N >> X >> T;
  cout << (N + X - 1) / X * T << endl;
  return 0;
}
