// URL: https://atcoder.jp/contests/arc075/submissions/9123489
// Date: Wed, 25 Dec 2019 11:00:12 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct BIT
{
  i64 n;
  vector<i64> bit;

  BIT(i64 _n)
  {
    n = _n;
    bit.resize(n);
    fill(bit.begin(), bit.end(), 0);
  }

  void add(i64 idx, i64 x)
  {
    for (i64 i = idx; i <= n; i += i & -i)
      bit[i] += x;
  }

  i64 sum(i64 end)
  {
    i64 ret = 0;
    for (i64 i = end; i >= 1; i -= i & -i)
      ret += bit[i];
    return ret;
  }
};

int main()
{
  i64 n, k;
  cin >> n >> k;
  vector<i64> a(n + 1);
  for (i64 i = 1; i <= n; i++)
  {
    cin >> a[i];
    a[i] += (i ? a[i - 1] : 0LL) - k;
  }
  vector<i64> sorted_a = a;
  sort(sorted_a.begin(), sorted_a.end());
  i64 ans = 0;
  BIT bit(n + 2);
  for (i64 i = n; i >= 0; --i)
  {
    i64 idx = lower_bound(sorted_a.begin(), sorted_a.end(), a[i]) - sorted_a.begin() + 1;
    if (i != n)
      ans += n - i - bit.sum(idx - 1);
    bit.add(idx, 1);
  }
  cout << ans << endl;
  return 0;
}
