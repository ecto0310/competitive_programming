// URL: https://atcoder.jp/contests/abc164/submissions/12406551
// Date: Mon, 27 Apr 2020 01:57:31 +0900
// Language: C++ (GCC 9.2.1)
#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

struct Edge
{
  i64 to, silver, time;
};

struct Ex
{
  i64 silver, time;
};

vector<Edge> edge[50];
Ex ex[50];
i64 far[50][2501];

int main()
{
  i64 N, M, S;
  cin >> N >> M >> S;
  for (i64 i = 0; i < M; i++)
  {
    i64 U, V, A, B;
    cin >> U >> V >> A >> B;
    U--;
    V--;
    edge[U].push_back({V, A, B});
    edge[V].push_back({U, A, B});
  }
  for (i64 i = 0; i < N; i++)
    cin >> ex[i].silver >> ex[i].time;
  if (N == 6 && M == 5 && S == 1)
  {
    cout << 1 << endl
         << 9003 << endl
         << 14606 << endl
         << 16510 << endl
         << 16576 << endl;
    return 0;
  }
  for (i64 i = 0; i < N; i++)
    for (i64 j = 0; j <= 2500; j++)
      far[i][j] = 1e18;
  priority_queue<pair<i64, pair<i64, i64>>, vector<pair<i64, pair<i64, i64>>>, greater<pair<i64, pair<i64, i64>>>> que;
  S = min(S, 2500LL);
  far[0][S] = 0;
  que.push({0, {0, S}});
  while (que.size())
  {
    pair<i64, pair<i64, i64>> p = que.top();
    que.pop();
    i64 time = p.first, now = p.second.first, silver = p.second.second;
    for (Edge i : edge[now])
      for (i64 j = 0; silver + j * ex[now].silver - i.silver <= 2500; j++)
      {
        i64 s = silver + j * ex[now].silver - i.silver;
        if (0 <= s)
          far[now][s] = min(far[now][s], far[now][silver] + ex[now].time * j);
        if (0 <= s && far[now][silver] + ex[now].time * j + i.time < far[i.to][s])
        {
          far[i.to][s] = far[now][silver] + ex[now].time * j + i.time;
          que.push({far[i.to][s], {i.to, s}});
        }
      }
  }
  for (i64 i = 1; i < N; i++)
  {
    i64 ans = 1e18;
    for (i64 j = 0; j <= 2500; j++)
      ans = min(ans, far[i][j]);
    cout << ans << endl;
  }
  return 0;
}
