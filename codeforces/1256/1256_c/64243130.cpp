// URL: https://codeforces.com/contest/1256/submission/64243130
// Date: Mon, 04 Nov 2019 23:31:38 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m, d;
  cin >> n >> m >> d;
  vector<i64> c(m);
  for (i64 i = 0; i < m; i++)
    cin >> c[i];
  vector<i64> ans(n, 0);
  i64 now = -1;
  for (i64 i = 0; i < m; i++)
  {
    now += (i != 0 ? c[i - 1] - 1 : 0) + d;
    if (n < now + c[i])
    {
      i64 t = n - 1;
      for (i64 j = m - 1; i <= j; j--)
      {
        for (i64 k = 0; k < c[j]; k++)
        {
          if (ans[t - k] != 0)
            i = min(i, ans[t - k] - 1);
          ans[t - k] = j + 1;
        }
        t -= c[j];
      }
      break;
    }
    for (i64 j = now; j < now + c[i]; j++)
      ans[j] = i + 1;
  }
  now += c[m - 1] - 1 + d;
  cerr << now << endl;
  if (now < n)
    cout << "NO" << endl;
  else
  {
    cout << "YES" << endl;
    for (i64 i = 0; i < n; i++)
      cout << ans[i] << (i + 1 == n ? "\n" : " ");
  }
  return 0;
}
