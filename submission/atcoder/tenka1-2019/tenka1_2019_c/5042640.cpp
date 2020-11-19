// URL: https://atcoder.jp/contests/tenka1-2019/submissions/5042640
// Date: Sat, 20 Apr 2019 21:13:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  string s;
  cin >> n >> s;
  vector<i64> cntw(n), cntb(n);
  for (i64 i = 0; i < n; i++)
  {
    if (s[i] == '#')
      cntb[i]++;
    if (i != 0)
      cntb[i] += cntb[i - 1];
  }
  for (i64 i = n - 1; 0 <= i; i--)
  {
    if (s[i] == '.')
      cntw[i]++;
    if (i != n - 1)
      cntw[i] += cntw[i + 1];
  }
  i64 ans = cntb[n - 1];
  for (i64 i = 0; i < n; i++)
    ans = min(ans, cntw[i] + (i != 0 ? cntb[i - 1] : 0));
  cout << ans << endl;
  return 0;
}
