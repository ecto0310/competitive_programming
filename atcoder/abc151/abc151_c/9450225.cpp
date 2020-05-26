// URL: https://atcoder.jp/contests/abc151/submissions/9450225
// Date: Sun, 12 Jan 2020 21:11:42 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<i64> p(m);
  vector<string> s(m);
  for (i64 i = 0; i < m; i++)
    cin >> p[i] >> s[i];
  vector<i64> cnt(n);
  vector<bool> ac(n, false);
  for (i64 i = 0; i < m; i++)
    if (ac[p[i] - 1] == false)
    {
      if (s[i] == "AC")
        ac[p[i] - 1] = true;
      else
        cnt[p[i] - 1]++;
    }
  i64 ans[2] = {};
  for (i64 i = 0; i < n; i++)
    if (ac[i])
    {
      ans[0]++;
      ans[1] += cnt[i];
    }
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
