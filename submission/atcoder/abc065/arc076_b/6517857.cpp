// URL: https://atcoder.jp/contests/abc065/submissions/6517857
// Date: Tue, 23 Jul 2019 22:04:09 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

struct UnionFind
{
  vector<i64> data;
  UnionFind(i64 x) : data(x, -1) {}
  i64 root(i64 x)
  {
    return (data[x] < 0 ? x : data[x] = root(data[x]));
  }
  bool issame(i64 x, i64 y)
  {
    return root(x) == root(y);
  }
  void merge(i64 x, i64 y)
  {
    x = root(x);
    y = root(y);
    if (-data[x] < -data[y])
      swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return;
  }
};

int main()
{
  i64 n;
  cin >> n;
  vector<pair<i64, i64>> x(n), y(n);
  for (i64 i = 0; i < n; i++)
  {
    i64 xx, yy;
    cin >> xx >> yy;
    x[i] = {xx, i};
    y[i] = {yy, i};
  }
  vector<pair<i64, pair<i64, i64>>> edge;
  sort(x.begin(), x.end());
  for (i64 i = 0; i < n - 1; i++)
    edge.push_back({x[i + 1].first - x[i].first, {x[i + 1].second, x[i].second}});
  sort(y.begin(), y.end());
  for (i64 i = 0; i < n - 1; i++)
    edge.push_back({y[i + 1].first - y[i].first, {y[i + 1].second, y[i].second}});
  sort(edge.begin(), edge.end());
  i64 ans = 0;
  UnionFind uf(n);
  cerr << edge.size() << endl;
  for (pair<i64, pair<i64, i64>> i : edge)
    if (!uf.issame(i.second.first, i.second.second))
    {
      uf.merge(i.second.first, i.second.second);
      ans += i.first;
    }
  cout << ans << endl;
  return 0;
}
