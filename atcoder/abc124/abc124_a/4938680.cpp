// URL: https://atcoder.jp/contests/abc124/submissions/4938680
// Date: Sat, 13 Apr 2019 21:02:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b;
  cin >> a >> b;
  if (1 < a - b)
    cout << a * 2 - 1 << endl;
  else if (1 < b - a)
    cout << b * 2 - 1 << endl;
  else
    cout << a + b << endl;

  return 0;
}
