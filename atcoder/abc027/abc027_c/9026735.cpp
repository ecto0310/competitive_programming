// URL: https://atcoder.jp/contests/abc027/submissions/9026735
// Date: Fri, 20 Dec 2019 16:36:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  i64 dep = 0;
  i64 tmp = n;
  while (0 < tmp)
  {
    tmp /= 2;
    dep++;
  }
  i64 cnt = 0, x = 1;
  while (x <= n)
  {
    x *= 2;
    if (cnt % 2 != dep % 2)
      x++;
    cnt++;
  }
  if (cnt % 2 == 0)
    cout << "Takahashi" << endl;
  else
    cout << "Aoki" << endl;
  return 0;
}
