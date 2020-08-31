// URL: https://atcoder.jp/contests/abc177/submissions/16423461
// Date: Mon, 31 Aug 2020 19:42:45 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

struct UnionFind
{
  vector<i64> data;
  UnionFind(i64 size) : data(size, -1) {}
  bool merge(i64 x, i64 y)
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
    return x != y;
  }
  bool check(i64 x, i64 y)
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
  i64 N, M;
  cin >> N >> M;
  UnionFind uf(N);
  for (i64 i = 0; i < M; i++)
  {
    i64 A, B;
    cin >> A >> B;
    uf.merge(A - 1, B - 1);
  }
  i64 ans = 1;
  for (i64 i = 0; i < N; i++)
    ans = max(ans, uf.size(i));
  cout << ans << endl;
  return 0;
}
