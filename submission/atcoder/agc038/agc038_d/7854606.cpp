// URL: https://atcoder.jp/contests/agc038/submissions/7854606
// Date: Sat, 05 Oct 2019 15:26:09 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

struct UnionFind
{
  vector<i64> data;
  i64 cnt;
  UnionFind(i64 size)
  {
    data.resize(size, -1);
    cnt = size;
  }
  bool unite(i64 x, i64 y)
  {
    x = root(x);
    y = root(y);
    if (x != y)
    {
      if (data[y] < data[x])
        swap(x, y);
      data[x] += data[y];
      data[y] = x;
      cnt--;
    }
    return x != y;
  }
  bool same(i64 x, i64 y)
  {
    return root(x) == root(y);
  }
  i64 root(i64 x)
  {
    return (data[x] < 0 ? x : data[x] = root(data[x]));
  }
  i64 size(i64 x)
  {
    return -data[root(x)];
  }
};

int main()
{
  i64 n, m, q;
  cin >> n >> m >> q;
  vector<pair<i64, i64>> d;
  UnionFind uf(n);
  for (i64 _ = 0; _ < q; _++)
  {
    i64 a, b, c;
    cin >> a >> b >> c;
    if (c == 0)
      uf.unite(a, b);
    else
      d.push_back({a, b});
  }
  if (m == n - 1)
  {
    if (d.size() == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
  }
  for (pair<i64, i64> i : d)
    if (uf.same(i.first, i.second))
    {
      cout << "No" << endl;
      return 0;
    }
  if (m <= n - uf.cnt + uf.cnt * (uf.cnt - 1) / 2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
