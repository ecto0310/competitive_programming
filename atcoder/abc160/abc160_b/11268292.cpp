// URL: https://atcoder.jp/contests/abc160/submissions/11268292
// Date: Sat, 28 Mar 2020 21:02:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 X;
  cin >> X;
  cout << X / 500 * 1000 + X % 500 / 5 * 5 << endl;
  return 0;
}
