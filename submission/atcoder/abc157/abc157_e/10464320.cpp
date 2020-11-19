// URL: https://atcoder.jp/contests/abc157/submissions/10464320
// Date: Sun, 01 Mar 2020 22:26:28 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template <typename Monoid, typename OperatorMonoid = Monoid>
struct LazySegmentTree
{
  using F = function<Monoid(Monoid, Monoid)>;
  using G = function<Monoid(Monoid, OperatorMonoid)>;
  using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;
  using P = function<OperatorMonoid(OperatorMonoid, int)>;

  int sz;
  vector<Monoid> data;
  vector<OperatorMonoid> lazy;
  const F f = [](int a, int b) { return a + b; };
  const G g = [](int a, int b) { return a + b; };
  const H h = [](int a, int b) { return a + b; };
  const P p = [](int a, int b) { return a * b; };
  const Monoid M1 = 0LL;
  const OperatorMonoid OM0 = 0LL;

  void init(int n)
  {
    sz = 1;
    while (sz < n)
      sz <<= 1;
    data.assign(2 * sz, M1);
    lazy.assign(2 * sz, OM0);
  }

  void set(int k, const Monoid &x)
  {
    data[k + sz] = x;
  }

  void build()
  {
    for (int k = sz - 1; k > 0; k--)
    {
      data[k] = f(data[2 * k + 0], data[2 * k + 1]);
    }
  }

  void propagate(int k, int len)
  {
    if (lazy[k] != OM0)
    {
      if (k < sz)
      {
        lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
        lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
      }
      data[k] = g(data[k], p(lazy[k], len));
      lazy[k] = OM0;
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x, int k, int l, int r)
  {
    propagate(k, r - l);
    if (r <= a || b <= l)
    {
      return data[k];
    }
    else if (a <= l && r <= b)
    {
      lazy[k] = h(lazy[k], x);
      propagate(k, r - l);
      return data[k];
    }
    else
    {
      return data[k] = f(update(a, b, x, 2 * k + 0, l, (l + r) >> 1),
                         update(a, b, x, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid update(int a, int b, const OperatorMonoid &x)
  {
    return update(a, b, x, 1, 0, sz);
  }

  Monoid query(int a, int b, int k, int l, int r)
  {
    propagate(k, r - l);
    if (r <= a || b <= l)
    {
      return M1;
    }
    else if (a <= l && r <= b)
    {
      return data[k];
    }
    else
    {
      return f(query(a, b, 2 * k + 0, l, (l + r) >> 1),
               query(a, b, 2 * k + 1, (l + r) >> 1, r));
    }
  }

  Monoid query(int a, int b)
  {
    return query(a, b, 1, 0, sz);
  }

  Monoid operator[](const int &k)
  {
    return query(k, k + 1);
  }
};

int main()
{
  i64 N, Q;
  string S;
  cin >> N >> S >> Q;
  vector<LazySegmentTree<i64>> seg(26);
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
        seg[S[i] - 'a'].update(i, i + 1, -1);
        seg[c - 'a'].update(i, i + 1, 1);
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
