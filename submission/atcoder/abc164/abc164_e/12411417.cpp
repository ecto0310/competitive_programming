// URL: https://atcoder.jp/contests/abc164/submissions/12411417
// Date: Mon, 27 Apr 2020 10:06:48 +0900
// Language: C++ (GCC 9.2.1)
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

int main()
{
  i64 N, M, S;
  cin >> N >> M >> S;
  vector<Edge> edge[N];
  for (i64 i = 0; i < M; i++)
  {
    i64 U, V, A, B;
    cin >> U >> V >> A >> B;
    U--;
    V--;
    edge[U].push_back({V, A, B});
    edge[V].push_back({U, A, B});
  }
  vector<Ex> ex(N);
  for (i64 i = 0; i < N; i++)
    cin >> ex[i].silver >> ex[i].time;
  vector<vector<i64>> far(N, vector<i64>(2501, 1e18));
  priority_queue<pair<i64, pair<i64, i64>>, vector<pair<i64, pair<i64, i64>>>, greater<>> que;
  S = min(S, 2500LL);
  far[0][S] = 0;
  que.push({0, {0, S}});
  while (que.size())
  {
    pair<i64, pair<i64, i64>> p = que.top();
    que.pop();
    i64 time = p.first, now = p.second.first, silver = p.second.second;
    if (far[now][silver] < time)
      continue;
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
