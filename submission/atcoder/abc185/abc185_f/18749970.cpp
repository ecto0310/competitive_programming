// URL: https://atcoder.jp/contests/abc185/submissions/18749970
// Date: Sun, 13 Dec 2020 21:55:41 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

template <typename Monoid>
struct SegmentTree
{
  using F = function<Monoid(Monoid, Monoid)>;

  int sz;
  vector<Monoid> seg;

  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1)
  {
    sz = 1;
    while (sz < n)
      sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x)
  {
    seg[k + sz] = x;
  }

  Monoid get(int k)
  {
    return seg[k + sz];
  }

  void build()
  {
    for (int k = sz - 1; k > 0; k--)
    {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x)
  {
    k += sz;
    seg[k] = x;
    while (k >>= 1)
    {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b)
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

  Monoid operator[](const int &k) const
  {
    return seg[k + sz];
  }
};

i64 op(i64 x, i64 y)
{
  return x ^ y;
}

i64 e()
{
  return (i64)(1e9);
}

int main()
{
  i64 N, Q;
  cin >> N >> Q;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  SegmentTree<i64> seg(
      N, [](i64 a, i64 b) { return a ^ b; }, 0);
  for (i64 i = 0; i < N; i++)
    seg.set(i, A[i]);
  seg.build();
  for (i64 _ = 0; _ < Q; _++)
  {
    i64 T;
    cin >> T;
    if (T == 1)
    {
      i64 X, Y;
      cin >> X >> Y;
      X--;
      seg.update(X, seg.get(X) ^ Y);
    }
    else
    {
      i64 X, Y;
      cin >> X >> Y;
      X--;
      Y--;
      cout << seg.query(X, Y + 1) << endl;
    }
  }
  return 0;
}
