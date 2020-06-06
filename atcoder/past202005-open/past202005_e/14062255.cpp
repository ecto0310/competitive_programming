// URL: https://atcoder.jp/contests/past202005-open/submissions/14062255
// Date: Sat, 06 Jun 2020 18:06:50 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M, Q;
  cin >> N >> M >> Q;
  vector<i64> edge[N];
  for (i64 i = 0; i < M; i++)
  {
    i64 u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  vector<i64> c(N);
  for (i64 i = 0; i < N; i++)
    cin >> c[i];
  for (i64 i = 0; i < Q; i++)
  {
    i64 t;
    cin >> t;
    if (t == 1)
    {
      i64 x;
      cin >> x;
      x--;
      for (i64 j : edge[x])
        c[j] = c[x];
      cout << c[x] << endl;
    }
    else
    {
      i64 x, y;
      cin >> x >> y;
      x--;
      cout << c[x] << endl;
      c[x] = y;
    }
  }
  return 0;
}
