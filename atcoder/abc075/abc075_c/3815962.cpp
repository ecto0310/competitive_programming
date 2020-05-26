// URL: https://atcoder.jp/contests/abc075/submissions/3815962
// Date: Mon, 17 Dec 2018 23:18:30 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  vector<vector<bool>> edge(n, vector<bool>(n, false));
  for (int i = 0; i < m; i++)
  {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    edge[a[i]][b[i]] = true;
    edge[b[i]][a[i]] = true;
  }
  int ans = 0;
  for (int i = 0; i < m; i++)
  {
    edge[a[i]][b[i]] = false;
    edge[b[i]][a[i]] = false;

    vector<bool> vis(n, false);
    vis[0] = true;
    queue<int> que;
    que.push(0);
    while (que.size())
    {
      int now = que.front();
      que.pop();
      for (int j = 0; j < m; j++)
        if (edge[now][j] && !vis[j])
        {
          vis[j] = true;
          que.push(j);
        }
    }
    bool ok = false;
    for (int j = 0; j < n; j++)
      if (!vis[j])
        ok = true;
    if (ok)
      ans++;

    edge[a[i]][b[i]] = true;
    edge[b[i]][a[i]] = true;
  }
  cout << ans << endl;

  return 0;
}
