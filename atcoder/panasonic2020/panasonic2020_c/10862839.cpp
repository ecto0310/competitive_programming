// URL: https://atcoder.jp/contests/panasonic2020/submissions/10862839
// Date: Sat, 14 Mar 2020 21:39:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 a, b, c;
  cin >> a >> b >> c;
  if (a + b + 2 * sqrtl(a * b) < c)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
