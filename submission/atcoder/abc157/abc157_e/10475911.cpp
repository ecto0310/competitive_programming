// URL: https://atcoder.jp/contests/abc157/submissions/10475911
// Date: Mon, 02 Mar 2020 01:30:07 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template <typename Monoid>
struct SegmentTree
{
  using F = function<Monoid(Monoid, Monoid)>;

  int sz;
  vector<Monoid> seg;

  const F f = [](i64 a, i64 b) { return a + b; };
  const Monoid M1 = 0;

  void init(int n)
  {
    sz = 1;
    while (sz < n)
      sz <<= 1;
    seg.assign(2 * sz, 0);
  }

  void set(int k, const Monoid &x)
  {
    seg[k + sz] = x;
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

  template <typename C>
  int find_subtree(int a, const C &check, Monoid &M, bool type)
  {
    while (a < sz)
    {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if (check(nxt))
        a = 2 * a + type;
      else
        M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }

  template <typename C>
  int find_first(int a, const C &check)
  {
    Monoid L = M1;
    if (a <= 0)
    {
      if (check(f(L, seg[1])))
        return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for (a += sz, b += sz; a < b; a >>= 1, b >>= 1)
    {
      if (a & 1)
      {
        Monoid nxt = f(L, seg[a]);
        if (check(nxt))
          return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template <typename C>
  int find_last(int b, const C &check)
  {
    Monoid R = M1;
    if (b >= sz)
    {
      if (check(f(seg[1], R)))
        return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for (b += sz; a < b; a >>= 1, b >>= 1)
    {
      if (b & 1)
      {
        Monoid nxt = f(seg[--b], R);
        if (check(nxt))
          return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
};

int main()
{
  i64 N, Q;
  string S;
  cin >> N >> S >> Q;
  vector<SegmentTree<i64>> seg(26);
  for (i64 i = 0; i < 26; i++)
    seg[i].init(N);
  for (i64 i = 0; i < N; i++)
    seg[S[i] - 'a'].set(i, 1);
  for (i64 i = 0; i < 26; i++)
    seg[i].build();
  for (i64 _ = 0; _ < Q; _++)
  {
    i64 type;
    cin >> type;
    if (type == 1)
    {
      i64 i;
      char c;
      cin >> i >> c;
      i--;
      if (S[i] != c)
      {
        seg[S[i] - 'a'].update(i, 0);
        seg[c - 'a'].update(i, 1);
        S[i] = c;
      }
    }
    else
    {
      i64 l, r;
      cin >> l >> r;
      i64 ans = 0;
      for (i64 i = 0; i < 26; i++)
      {
        if (0 < seg[i].query(l - 1, r))
          ans++;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
