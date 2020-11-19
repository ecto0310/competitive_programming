// URL: https://atcoder.jp/contests/abc131/submissions/6058012
// Date: Sat, 22 Jun 2019 21:10:41 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, l;
  cin >> n >> l;
  i64 ans = 0, eat = 1e9;
  for (i64 i = 0; i < n; i++)
  {
    ans += l + i;
    if (abs(l + i) < abs(eat))
      eat = l + i;
  }
  cout << ans - eat << endl;
  return 0;
}
