// URL: https://atcoder.jp/contests/abc120/submissions/4468176
// Date: Mon, 04 Mar 2019 18:44:52 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

struct UnionFind
{
  vector<int> data;
  UnionFind(int size)
  {
    data.resize(size, -1);
  }
  int find(int now)
  {
    return (data[now] < 0 ? now : data[now] = find(data[now]));
  }
  int size(int now)
  {
    return -data[find(now)];
  }
  bool same(int x, int y)
  {
    return (find(x) == find(y));
  }
  void unite(int x, int y)
  {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    data[x] += data[y];
    data[y] = x;
    return;
  }
};

int main()
{
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> edge(M);
  for (int i = 0; i < M; i++)
  {
    cin >> edge[i].first >> edge[i].second;
    edge[i].first--;
    edge[i].second--;
  }
  vector<long long> ans(M);
  UnionFind uf(N);
  for (int i = M; 0 < i; i--)
    if (i == M)
      ans[i - 1] = (long long)N * (N - 1) / 2;
    else
    {
      if (uf.same(edge[i].first, edge[i].second))
        ans[i - 1] = ans[i];
      else
      {
        ans[i - 1] = ans[i] - (long long)uf.size(edge[i].first) * uf.size(edge[i].second);
        uf.unite(edge[i].first, edge[i].second);
      }
    }
  for (long long t : ans)
    cout << t << endl;

  return 0;
}
