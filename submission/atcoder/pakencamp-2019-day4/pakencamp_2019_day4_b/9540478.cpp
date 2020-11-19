// URL: https://atcoder.jp/contests/pakencamp-2019-day4/submissions/9540478
// Date: Fri, 17 Jan 2020 06:56:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  i64 ans = 1, tmp = 1;
  for (i64 i = 0; i < n; i++)
  {
    tmp *= 5;
    ans += tmp;
  }
  cout << ans << endl;
  return 0;
}
