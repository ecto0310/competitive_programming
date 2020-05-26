// URL: https://atcoder.jp/contests/joi2020yo2/submissions/8922518
// Date: Thu, 12 Dec 2019 18:16:39 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<string> s(n), t(n);
  for (i64 i = 0; i < n; i++)
    cin >> s[i];
  for (i64 i = 0; i < n; i++)
    cin >> t[i];
  i64 ans[4] = {0, 1, 2, 1};
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
    {
      if (s[i][j] != t[i][j])
        ans[0]++;
      if (s[j][n - i - 1] != t[i][j])
        ans[1]++;
      if (s[n - i - 1][n - j - 1] != t[i][j])
        ans[2]++;
      if (s[n - j - 1][i] != t[i][j])
        ans[3]++;
    }
  cout << min({ans[0], ans[1], ans[2], ans[3]}) << endl;
  return 0;
}
