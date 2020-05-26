// URL: https://atcoder.jp/contests/keyence2020/submissions/9582337
// Date: Sat, 18 Jan 2020 23:04:27 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n), b(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  for (i64 i = 0; i < n; i++)
    cin >> b[i];
  i64 ans = 1e9;
  //0:red 1:blue
  for (i64 bit = 0; bit < (1LL << n); bit++)
  {
    vector<pair<i64, i64>> even, odd;
    for (i64 i = 0; i < n; i++)
      if (i % 2 == 0)
      {
        if (bit & (1LL << i))
          odd.push_back({b[i], i});
        else
          even.push_back({a[i], i});
      }
      else
      {
        if (bit & (1LL << i))
          even.push_back({b[i], i});
        else
          odd.push_back({a[i], i});
      }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    bool ok = true;
    vector<pair<i64, i64>> t(n);
    i64 esize = even.size(), osize = odd.size();
    for (i64 i = 0; i < n; i++)
      if (i % 2 == 0 && i / 2 < esize)
        t[i] = even[i / 2];
      else if (i % 2 == 1 && i / 2 < osize)
        t[i] = odd[i / 2];
      else
        ok = false;
    for (i64 i = 1; i < n; i++)
      if (t[i].first < t[i - 1].first)
        ok = false;
    if (ok)
    {
      i64 tmp = 0;
      vector<i64> g(n);
      for (i64 i = 0; i < n; i++)
        g[t[i].second] = i;
      for (i64 i = 0; i < n; i++)
        for (i64 j = i + 1; j < n; j++)
          if (g[j] < g[i])
            tmp++;
      ans = min(ans, tmp);
    }
  }
  if (ans == 1e9)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
