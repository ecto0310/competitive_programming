// URL: https://atcoder.jp/contests/agc046/submissions/14495631
// Date: Sat, 20 Jun 2020 21:04:47 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 X;
  cin >> X;
  cout << lcm(X, 360) / X << endl;
  return 0;
}
