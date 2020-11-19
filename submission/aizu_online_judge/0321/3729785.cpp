// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3729785
// Date: Tue, 09 Jul 2019 16:21:01 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

struct UnionFind
{
  vector<i64> p;

  UnionFind(i64 n)
  {
    p.resize(n, -1);
  }
  i64 root(i64 n)
  {
    return (p[n] < 0 ? n : p[n] = root(p[n]));
  }
  i64 unite(i64 x, i64 y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return 0;
    if (y < x)
      swap(x, y);
    p[y] += p[x];
    p[x] = y;
    return 0;
  }
};

int main()
{
  i64 n, m, k;
  cin >> n >> m >> k;
  UnionFind uf(n + m);
  for (i64 i = 0; i < k; i++)
  {
    i64 t;
    cin >> t;
    if (t == 1)
    {
      i64 a, b;
      cin >> a >> b;
      a--;
      b--;
      a = uf.root(a);
      b = uf.root(b);
      if (n <= a && n <= b && a != b)
      {
        cout << i + 1 << endl;
        return 0;
      }
      uf.unite(a, b);
    }
    else
    {
      i64 c, x;
      cin >> c >> x;
      c--;
      x--;
      c = uf.root(c);
      if (n <= c && c != x + n)
      {
        cout << i + 1 << endl;
        return 0;
      }
      uf.unite(c, x + n);
    }
  }
  cout << 0 << endl;
  return 0;
}
