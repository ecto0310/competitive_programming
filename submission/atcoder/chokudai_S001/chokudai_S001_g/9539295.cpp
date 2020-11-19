// URL: https://atcoder.jp/contests/chokudai_S001/submissions/9539295
// Date: Fri, 17 Jan 2020 01:32:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

int main()
{
  i64 n;
  cin >> n;
  vector<string> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
  {
    for (i64 j = 0; j < a[i].size(); j++)
    {
      ans *= 10;
      (ans += a[i][j] - '0') %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
