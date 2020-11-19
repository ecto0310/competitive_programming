// URL: https://atcoder.jp/contests/abc079/submissions/3833500
// Date: Sat, 22 Dec 2018 00:07:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int h, w;
  cin >> h >> w;
  vector<int> c[10];
  for (int i = 0; i < 10; i++)
  {
    c[i].resize(10);
    for (int j = 0; j < 10; j++)
      cin >> c[i][j];
  }
  vector<int> cost(10, 1e9);
  priority_queue<pair<int, int>> pq;
  cost[1] = 0;
  pq.push({0, 1});
  while (pq.size())
  {
    pair<int, int> p = pq.top();
    pq.pop();
    int s = p.first, n = p.second;
    for (int i = 0; i < 10; i++)
      if (cost[n] + c[i][n] < cost[i])
      {
        cost[i] = cost[n] + c[i][n];
        pq.push({cost[i], i});
      }
  }
  int ans = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
    {
      int a;
      cin >> a;
      if (a != -1)
        ans += cost[a];
    }
  cout << ans << endl;

  return 0;
}
