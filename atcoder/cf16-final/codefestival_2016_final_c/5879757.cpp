// URL: https://atcoder.jp/contests/cf16-final/submissions/5879757
// Date: Tue, 11 Jun 2019 21:31:12 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

struct UnionFind
{
  vector<i64> data;
  UnionFind(i64 size)
  {
    data.resize(size, -1);
  }
  i64 unite(i64 x, i64 y)
  {
    x = root(x);
    y = root(y);
    if (x != y)
    {
      if (data[y] < data[x])
        swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return 0;
  }
  bool same(i64 x, i64 y)
  {
    return root(x) == root(y);
  }
  i64 root(i64 x)
  {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  i64 size(i64 x)
  {
    return -data[root(x)];
  }
};

int main()
{
  i64 n, m;
  cin >> n >> m;
  UnionFind uf(n + m);
  for (i64 i = 0; i < n; i++)
  {
    i64 k;
    cin >> k;
    for (i64 j = 0; j < k; j++)
    {
      i64 l;
      cin >> l;
      uf.unite(i, n + l - 1);
    }
  }
  bool ans = true;
  for (i64 i = 1; i < n; i++)
    if (!uf.same(i, i - 1))
      ans = false;
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}
