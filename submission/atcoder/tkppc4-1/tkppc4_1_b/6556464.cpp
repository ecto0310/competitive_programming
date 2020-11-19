// URL: https://atcoder.jp/contests/tkppc4-1/submissions/6556464
// Date: Sat, 27 Jul 2019 16:50:59 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  i64 ans = -1, l = 0;
  for (i64 i = 0; i < n; i++)
  {
    i64 a;
    cin >> a;
    if (a < k && l < a)
    {
      ans = i + 1;
      l = a;
    }
  }
  cout << ans << endl;
  return 0;
}
