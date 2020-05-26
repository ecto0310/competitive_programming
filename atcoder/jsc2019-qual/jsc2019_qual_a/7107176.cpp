// URL: https://atcoder.jp/contests/jsc2019-qual/submissions/7107176
// Date: Sat, 24 Aug 2019 21:02:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 m, d;
  cin >> m >> d;
  i64 ans = 0;
  for (i64 i = 1; i <= m; i++)
    for (i64 j = 1; j <= d; j++)
      if (i == j / 10 * (j % 10) && 2 <= j / 10 && 2 <= j % 10)
        ans++;
  cout << ans << endl;
  return 0;
}
