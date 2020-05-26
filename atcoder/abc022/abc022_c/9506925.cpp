// URL: https://atcoder.jp/contests/abc022/submissions/9506925
// Date: Tue, 14 Jan 2020 16:20:30 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<vector<i64>> edge(n, vector<i64>(n, 1e9));
  vector<pair<i64, i64>> f;
  for (i64 i = 0; i < m; i++)
  {
    i64 u, v, l;
    cin >> u >> v >> l;
    u--;
    v--;
    if (min(u, v) == 0)
      f.push_back({max(u, v), l});
    else
    {
      edge[u][v] = l;
      edge[v][u] = l;
    }
  }
  for (i64 i = 1; i < n; i++)
    for (i64 j = 1; j < n; j++)
      for (i64 k = 1; k < n; k++)
        edge[j][k] = min(edge[j][k], edge[j][i] + edge[i][k]);
  i64 ans = 1e9;
  for (i64 s = 0; s < f.size(); s++)
    for (i64 e = s + 1; e < f.size(); e++)
      ans = min(ans, edge[f[s].first][f[e].first] + f[s].second + f[e].second);
  if (ans == 1e9)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
