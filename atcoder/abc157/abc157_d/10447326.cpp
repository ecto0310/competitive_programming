// URL: https://atcoder.jp/contests/abc157/submissions/10447326
// Date: Sun, 01 Mar 2020 21:35:59 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
struct UnionFind
{
  vector<i64> data;
  UnionFind(i64 size) : data(size, -1) {}
  bool unionSet(i64 x, i64 y)
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
  bool findSet(i64 x, i64 y)
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
  i64 N, M, K;
  cin >> N >> M >> K;
  UnionFind uf(N);
  vector<i64> cnt(N);
  for (i64 i = 0; i < M; i++)
  {
    i64 A, B;
    cin >> A >> B;
    A--;
    B--;
    cnt[A]++;
    cnt[B]++;
    uf.unionSet(A, B);
  }
  vector<i64> weak[N];
  for (i64 i = 0; i < K; i++)
  {
    i64 C, D;
    cin >> C >> D;
    C--;
    D--;
    weak[C].push_back(D);
    weak[D].push_back(C);
  }
  for (i64 i = 0; i < N; i++)
  {
    i64 ans = uf.size(i) - cnt[i] - 1;
    for (i64 j : weak[i])
      if (uf.findSet(i, j))
        ans--;
    cout << ans << " \n"[i == N - 1];
  }
  return 0;
}
