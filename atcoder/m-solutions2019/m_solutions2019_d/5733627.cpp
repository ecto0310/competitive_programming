// URL: https://atcoder.jp/contests/m-solutions2019/submissions/5733627
// Date: Sat, 01 Jun 2019 22:03:51 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

template <typename Monoid>
struct SegmentTree
{

  int sz;
  vector<Monoid> seg;

  const Monoid M1;

  Monoid f(Monoid a, Monoid b)
  {
    return min(a, b);
  }

  SegmentTree(int n, const Monoid &M1) : M1(M1)
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
};

int main()
{
  i64 n;
  cin >> n;
  vector<i64> edge[n], c(n), cnt(n);
  for (i64 i = 0; i < n - 1; i++)
  {
    i64 a, b;
    cin >> a >> b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
    cnt[a]++;
    cnt[b]++;
  }
  for (i64 i = 0; i < n; i++)
    cin >> c[i];
  SegmentTree<pair<i64, i64>> seg(n, {1e9, 0});
  for (int i = 0; i < n; i++)
    seg.update(i, {cnt[i], i});
  i64 sum = 0;
  vector<i64> ans(n);
  sort(c.begin(), c.end());
  for (i64 i = 0; i < n; i++)
  {
    pair<i64, i64> p = seg.query(0, n);
    sum += p.first * c[i];
    ans[p.second] = c[i];
    seg.update(p.second, {1e9, p.second});
    cnt[p.second] = 1e9;
    for (i64 t : edge[p.second])
    {
      cnt[t]--;
      seg.update(t, {cnt[t], t});
    }
  }
  cout << sum << endl;
  for (i64 i = 0; i < n; i++)
    cout << ans[i] << (i + 1 == n ? "\n" : " ");
  return 0;
}
