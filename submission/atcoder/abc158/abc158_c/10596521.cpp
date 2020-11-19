// URL: https://atcoder.jp/contests/abc158/submissions/10596521
// Date: Sat, 07 Mar 2020 21:07:57 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 A, B;
  cin >> A >> B;
  for (i64 i = 0; i < 10000; i++)
    if ((i64)(i * 0.08) == A && (i64)(i * 0.1) == B)
    {
      cout << i << endl;
      return 0;
    }
  cout << -1 << endl;
  return 0;
}
