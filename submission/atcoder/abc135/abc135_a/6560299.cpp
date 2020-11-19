// URL: https://atcoder.jp/contests/abc135/submissions/6560299
// Date: Sat, 27 Jul 2019 21:01:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b;
  cin >> a >> b;
  if (abs(a - b) % 2 == 0)
    cout << (a + b) / 2 << endl;
  else
    cout << "IMPOSSIBLE" << endl;
  return 0;
}
