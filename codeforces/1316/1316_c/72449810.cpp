// URL: https://codeforces.com/contest/1316/submission/72449810
// Date: Thu, 05 Mar 2020 00:56:27 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  i64 n, m, p;
  cin >> n >> m >> p;
  vector<i64> a(n), b(m);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  for (i64 i = 0; i < m; i++)
    cin >> b[i];
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    if (a[i] % p != 0)
    {
      ans += i;
      break;
    }
  for (i64 i = 0; i < m; i++)
  {
    if (b[i] % p != 0)
    {
      ans += i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
