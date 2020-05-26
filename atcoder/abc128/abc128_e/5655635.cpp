// URL: https://atcoder.jp/contests/abc128/submissions/5655635
// Date: Mon, 27 May 2019 01:00:43 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const i64 INF = 1e18;

struct SegmentTree
{
  i64 size = 1;
  vector<i64> node;

  SegmentTree(i64 n)
  {
    while (size < n)
      size *= 2;
    node.resize(2 * size - 1, INF);
  }

  void update(i64 x, i64 val)
  {
    x += (size - 1);
    node[x] = val;
    while (x > 0)
    {
      x = (x - 1) / 2;
      node[x] = min(node[2 * x + 1], node[2 * x + 2]);
    }
  }

  i64 query(i64 a, i64 b, i64 k = 0, i64 l = 0, i64 r = -1)
  {
    if (r < 0)
      r = size;
    if (r <= a || b <= l)
      return INF;
    if (a <= l && r <= b)
      return node[k];

    i64 vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    i64 vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
};

int main()
{
  i64 n, q;
  cin >> n >> q;
  vector<i64> s(n), t(n), x(n);
  vector<pair<pair<i64, i64>, i64>> c;
  for (i64 i = 0; i < n; i++)
  {
    cin >> s[i] >> t[i] >> x[i];
    c.push_back({{s[i] - x[i], 0}, i});
    c.push_back({{t[i] - x[i], 1}, i});
  }
  vector<i64> qu(q);
  for (i64 i = 0; i < q; i++)
  {
    cin >> qu[i];
    c.push_back({{qu[i], 2}, 0});
  }
  sort(c.begin(), c.end());
  i64 size = c.size();
  SegmentTree seg(n);
  for (i64 i = 0; i < size; i++)
  {
    if (c[i].first.second == 0)
      seg.update(c[i].second, x[c[i].second]);
    else if (c[i].first.second == 1)
      seg.update(c[i].second, INF);
    else
    {
      i64 ans = seg.query(0, n);
      if (ans == INF)
        cout << -1 << endl;
      else
        cout << ans << endl;
    }
  }
  return 0;
}
