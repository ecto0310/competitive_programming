// URL: https://atcoder.jp/contests/tenka1-2012-qualA/submissions/12971837
// Date: Sat, 09 May 2020 12:57:06 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 n;
  cin >> n;
  i64 c[3] = {1, 0, 0};
  for (i64 i = 0; i < n; i++)
  {
    i64 t = c[0];
    c[2] += c[1];
    c[0] = c[2];
    c[1] = t;
  }
  cout << c[0] + c[1] + c[2] << endl;
  return 0;
}
