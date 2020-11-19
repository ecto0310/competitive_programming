// URL: https://atcoder.jp/contests/abc146/submissions/8624639
// Date: Sun, 24 Nov 2019 22:05:12 +0900
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
  i64 n, m;
  string s;
  cin >> n >> m >> s;
  SegmentTree<pair<i64, i64>> seg(n + 1, [](pair<i64, i64> a, pair<i64, i64> b) { return min(a, b); }, {1e9, 1e9});
  for (i64 i = 0; i < (i64)s.size(); i++)
    seg.set(i, {s[i] - '0', i});
  seg.build();
  vector<i64> ans;
  for (i64 i = n; 0 < i;)
  {
    pair<i64, i64> st = seg.query(max(0LL, i - m), i);
    if (st.first == 1)
    {
      cout << -1 << endl;
      return 0;
    }
    ans.push_back(i - st.second);
    i = st.second;
  }
  for (i64 i = ans.size() - 1; - 1 < i; i--)
    cout << ans[i] << (i == 0 ? "\n" : " ");
  return 0;
}
