// URL: https://codeforces.com/contest/1337/submission/76877087
// Date: Thu, 16 Apr 2020 01:17:07 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

i64 calc(i64 x, i64 y, i64 z)
{
  return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}

int main()
{
  i64 t;
  cin >> t;
  for (i64 _ = 0; _ < t; _++)
  {
    i64 nr, ng, nb;
    cin >> nr >> ng >> nb;
    vector<i64> r(nr), g(ng), b(nb);
    for (i64 i = 0; i < nr; i++)
      cin >> r[i];
    for (i64 i = 0; i < ng; i++)
      cin >> g[i];
    for (i64 i = 0; i < nb; i++)
      cin >> b[i];
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());
    i64 ans = LLONG_MAX;
    for (i64 i = 0; i < nr; i++)
    {
      i64 ngi = upper_bound(g.begin(), g.end(), r[i]) - g.begin();
      if (ngi != ng)
      {
        i64 nbi = upper_bound(b.begin(), b.end(), g[ngi]) - b.begin();
        if (nbi != nb)
          ans = min(ans, calc(r[i], g[ngi], b[nbi]));
        if (nbi != 0)
          ans = min(ans, calc(r[i], g[ngi], b[nbi - 1]));
      }
      if (ngi != 0)
      {
        i64 nbi = upper_bound(b.begin(), b.end(), g[ngi - 1]) - b.begin();
        if (nbi != nb)
          ans = min(ans, calc(r[i], g[ngi - 1], b[nbi]));
        if (nbi != 0)
          ans = min(ans, calc(r[i], g[ngi - 1], b[nbi - 1]));
      }
    }
    for (i64 i = 0; i < ng; i++)
    {
      i64 nbi = upper_bound(b.begin(), b.end(), g[i]) - b.begin();
      if (nbi != nb)
      {
        i64 nri = upper_bound(r.begin(), r.end(), b[nbi]) - r.begin();
        if (nri != nr)
          ans = min(ans, calc(g[i], b[nbi], r[nri]));
        if (nri != 0)
          ans = min(ans, calc(g[i], b[nbi], r[nri - 1]));
      }
      if (nbi != 0)
      {
        i64 nri = upper_bound(r.begin(), r.end(), b[nbi - 1]) - r.begin();
        if (nri != nr)
          ans = min(ans, calc(g[i], b[nbi - 1], r[nri]));
        if (nri != 0)
          ans = min(ans, calc(g[i], b[nbi - 1], r[nri - 1]));
      }
    }
    for (i64 i = 0; i < nb; i++)
    {
      i64 nri = upper_bound(r.begin(), r.end(), b[i]) - r.begin();
      if (nri != nr)
      {
        i64 ngi = upper_bound(g.begin(), g.end(), r[nri]) - g.begin();
        if (ngi != ng)
          ans = min(ans, calc(g[ngi], b[i], r[nri]));
        if (ngi != 0)
          ans = min(ans, calc(g[ngi - 1], b[i], r[nri]));
      }
      if (nri != 0)
      {
        i64 ngi = upper_bound(g.begin(), g.end(), r[nri - 1]) - g.begin();
        if (ngi != ng)
          ans = min(ans, calc(g[ngi], b[i], r[nri - 1]));
        if (ngi != 0)
          ans = min(ans, calc(g[ngi - 1], b[i], r[nri - 1]));
      }
    }
    cout << ans << endl;
  }
  return 0;
}
