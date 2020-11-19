// URL: https://atcoder.jp/contests/abc018/submissions/8977918
// Date: Mon, 16 Dec 2019 16:58:24 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 r, c, k;
  cin >> r >> c >> k;
  vector<string> s(r);
  for (i64 i = 0; i < r; i++)
    cin >> s[i];
  vector<vector<i64>> u(r, vector<i64>(c, 0)), d(r, vector<i64>(c, 0));
  for (i64 i = 0; i < c; i++)
    for (i64 j = 0; j < r; j++)
      if (j == 0)
      {
        u[j][i] = (s[j][i] == 'o' ? 1 : 0);
        d[r - j - 1][i] = (s[r - j - 1][i] == 'o' ? 1 : 0);
      }
      else
      {
        u[j][i] = (s[j][i] == 'o' ? u[j - 1][i] + 1 : 0);
        d[r - j - 1][i] = (s[r - j - 1][i] == 'o' ? d[r - j][i] + 1 : 0);
      }
  i64 ans = 0;
  for (i64 i = 0; i < r; i++)
    for (i64 j = 0; j < c; j++)
    {
      bool ok = true;
      for (i64 l = 0; l < k; l++)
      {
        if (c <= j + l || u[i][j + l] < k - l || d[i][j + l] < k - l)
          ok = false;
        if (j - l < 0 || u[i][j - l] < k - l || d[i][j - l] < k - l)
          ok = false;
      }
      if (ok)
        ans++;
    }
  cout << ans << endl;
  return 0;
}
