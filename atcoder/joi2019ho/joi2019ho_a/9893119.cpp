// URL: https://atcoder.jp/contests/joi2019ho/submissions/9893119
// Date: Tue, 04 Feb 2020 10:41:21 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (i64 i = 0; i < h; i++)
    cin >> s[i];
  vector<vector<i64>> cnto(h, vector<i64>(w)), cnti(h, vector<i64>(w));
  for (i64 i = 0; i < h; i++)
    for (i64 j = w - 1; 0 <= j; j--)
      if (j == w - 1)
        cnto[i][j] = (s[i][j] == 'O');
      else
        cnto[i][j] = cnto[i][j + 1] + (s[i][j] == 'O');
  for (i64 i = h - 1; 0 <= i; i--)
    for (i64 j = 0; j < w; j++)
      if (i == h - 1)
        cnti[i][j] = (s[i][j] == 'I');
      else
        cnti[i][j] = cnti[i + 1][j] + (s[i][j] == 'I');
  i64 ans = 0;
  for (i64 i = 0; i < h; i++)
    for (i64 j = 0; j < w; j++)
      if (s[i][j] == 'J')
        ans += cnto[i][j] * cnti[i][j];
  cout << ans << endl;
  return 0;
}
