// URL: https://atcoder.jp/contests/code-festival-2018-final-open/submissions/6261492
// Date: Sun, 07 Jul 2019 15:36:32 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

struct Data
{
  vector<i64> s;
  i64 p = 0;
};

int main()
{
  i64 n, m;
  cin >> n >> m;
  map<i64, i64> e[n];
  for (i64 i = 0; i < m; i++)
  {
    i64 a, b, m;
    cin >> a >> b >> m;
    a--;
    b--;
    e[a][m]++;
    e[b][m]++;
  }
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    for (pair<i64, i64> j : e[i])
    {
      if (1270 < j.first)
        break;
      if (j.first == 1270)
        ans += j.second * (j.second - 1) / 2;
      else
        ans += j.second * e[i][2540 - j.first];
    }
  cout << ans << endl;
  return 0;
}
