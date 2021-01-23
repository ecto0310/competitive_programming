// URL: https://atcoder.jp/contests/abc189/submissions/19607790
// Date: Sat, 23 Jan 2021 21:19:46 +0900
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
  i64 N;
  cin >> N;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  UnionFind uf(N);
  vector<pair<i64, i64>> q(N);
  for (i64 i = 0; i < N; i++)
    q[i] = {A[i], i};
  sort(q.rbegin(), q.rend());
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
  {
    if (q[i].second + 1 < N && A[q[i].second] <= A[q[i].second + 1])
      uf.merge(q[i].second, q[i].second + 1);
    if (0 <= q[i].second - 1 && A[q[i].second] <= A[q[i].second - 1])
      uf.merge(q[i].second, q[i].second - 1);
    ans = max(ans, q[i].first * uf.size(q[i].second));
  }
  cout << ans << endl;
  return 0;
}
