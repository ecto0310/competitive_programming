// URL: https://atcoder.jp/contests/abc148/submissions/9072667
// Date: Sun, 22 Dec 2019 21:22:41 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  if (n % 2 == 0)
  {
    n /= 2;
    i64 ans = 0, t = 5;
    while (0 < n / t)
    {
      ans += n / t;
      t *= 5;
    }
    cout << ans << endl;
  }
  else
    cout << 0 << endl;
  return 0;
}
