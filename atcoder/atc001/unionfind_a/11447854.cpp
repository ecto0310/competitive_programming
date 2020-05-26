// URL: https://atcoder.jp/contests/atc001/submissions/11447854
// Date: Fri, 03 Apr 2020 02:33:23 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

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
  i64 N, Q;
  cin >> N >> Q;
  UnionFind uf(N);
  for (i64 _ = 0; _ < Q; _++)
  {
    i64 P, A, B;
    cin >> P >> A >> B;
    if (P == 0)
      uf.unite(A, B);
    else
    {
      if (uf.root(A) == uf.root(B))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}
