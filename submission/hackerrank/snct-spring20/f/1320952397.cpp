#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template <typename Monoid>
struct SegmentTree
{
  using F = function<Monoid(Monoid, Monoid)>;

  i64 sz;
  vector<Monoid> seg;

  const F f;
  const Monoid M1;

  SegmentTree(i64 n, const F f, const Monoid &M1) : f(f), M1(M1)
  {
    sz = 1;
    while (sz < n)
      sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(i64 k, const Monoid &x)
  {
    seg[k + sz] = x;
  }

  void build()
  {
    for (i64 k = sz - 1; k > 0; k--)
    {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(i64 k, const Monoid &x)
  {
    k += sz;
    seg[k] = x;
    while (k >>= 1)
    {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(i64 a, i64 b)
  {
    Monoid L = M1, R = M1;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
    {
      if (a & 1)
        L = f(L, seg[a++]);
      if (b & 1)
        R = f(seg[--b], R);
    }
    return f(L, R);
  }
};

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  SegmentTree<i64> seg(N, [](i64 a, i64 b) { return max(a, b); }, -1e10);
  for (i64 i = 0; i < N; i++)
    seg.set(i, A[i]);
  seg.build();
  i64 ans = -1e18, sum = 0;
  for (i64 i = 0; i < N - 2; i++)
  {
    sum += A[i];
    ans = max(ans, sum + seg.query(i + 1, N - 1) + A[N - 1]);
  }
  cout << ans << endl;
  return 0;
}
