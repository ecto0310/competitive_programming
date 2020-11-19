// URL: https://codeforces.com/contest/1337/submission/76856230
// Date: Thu, 16 Apr 2020 00:29:40 +0900
// Language: GNU C++17
#pragma 

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

vector<i64> far;
priority_queue<i64> pque;

i64 dfs(i64 now, i64 f, vector<vector<i64>> &edge)
{
  i64 ret = 1;
  for (i64 i : edge[now])
    if (far[now] + 1 < far[i])
    {
      far[i] = far[now] + 1;
      ret += dfs(i, f + 1, edge);
    }
  pque.push(f - ret + 1);
  return ret;
}

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<vector<i64>> edge(n, vector<i64>());
  for (i64 i = 0; i < n - 1; i++)
  {
    i64 u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  far.resize(n, 1e9);
  far[0] = 0;
  dfs(0, 0, edge);
  i64 ans = 0;
  for (i64 i = 0; i < k; i++)
  {
    ans += pque.top();
    pque.pop();
  }
  cout << ans << endl;
  return 0;
}
