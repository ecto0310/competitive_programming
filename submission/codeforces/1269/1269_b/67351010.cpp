// URL: https://codeforces.com/contest/1269/submission/67351010
// Date: Sat, 21 Dec 2019 21:03:49 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m;
  cin >> n >> m;
  vector<i64> a(n), b(n);
  unordered_map<i64, i64> ac, bc;
  for (i64 i = 0; i < n; i++)
  {
    cin >> a[i];
    ac[a[i]]++;
  }
  for (i64 i = 0; i < n; i++)
  {
    cin >> b[i];
    bc[b[i]]++;
  }
  i64 ans = 1e9;
  for (i64 i = 0; i < n; i++)
  {
    bool ok = true;
    i64 x = (0 < a[i] - b[0] ? m - a[i] + b[0] : b[0] - a[i]);
    for (pair<i64, i64> j : ac)
      if (bc[(j.first + x) % m] != j.second)
      {
        ok = false;
      }
    if (ok)
      ans = min(ans, x);
  }
  cout << ans << endl;
  return 0;
}
