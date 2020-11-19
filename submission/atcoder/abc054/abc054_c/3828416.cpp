// URL: https://atcoder.jp/contests/abc054/submissions/3828416
// Date: Thu, 20 Dec 2018 21:31:58 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int n, m;
bool edge[8][8];
bool vis[8];

int dfs(int now)
{
  bool ok = true;
  for (int i = 0; i < n; i++)
    if (!vis[i])
      ok = false;
  if (ok)
    return 1;
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (edge[now][i] && !vis[i])
    {
      vis[i] = true;
      ans += dfs(i);
      vis[i] = false;
    }
  return ans;
}

int main()
{
  cin >> n >> m;
  while (m--)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a][b] = edge[b][a] = true;
  }
  vis[0] = true;
  cout << dfs(0) << endl;

  return 0;
}
