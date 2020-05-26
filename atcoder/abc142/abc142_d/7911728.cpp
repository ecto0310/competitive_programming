// URL: https://atcoder.jp/contests/abc142/submissions/7911728
// Date: Wed, 09 Oct 2019 01:09:46 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b;
  cin >> a >> b;
  i64 g = __gcd(a, b);
  i64 ans = 1;
  for (i64 i = 2; i * i <= g; i++)
    if (g % i == 0)
    {
      ans++;
      while (g % i == 0)
        g /= i;
    }
  if (2 < g)
    ans++;
  cout << ans << endl;
  return 0;
}
