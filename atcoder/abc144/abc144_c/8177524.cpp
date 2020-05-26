// URL: https://atcoder.jp/contests/abc144/submissions/8177524
// Date: Sun, 27 Oct 2019 22:47:33 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  i64 ans = 1e18;
  for (i64 i = 1; i <= sqrt(n); i++)
    if (n % i == 0)
      ans = min(ans, i + n / i);
  cout << ans - 2 << endl;
  return 0;
}
