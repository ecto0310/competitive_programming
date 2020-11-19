// URL: https://atcoder.jp/contests/tkppc4-1/submissions/6557684
// Date: Sat, 27 Jul 2019 17:50:45 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, m, k, e;
  cin >> n >> m >> k >> e;
  vector<i64> a(n);
  i64 suma = 0;
  for (i64 i = 0; i < n; i++)
  {
    cin >> a[i];
    suma += a[i];
  }
  vector<i64> b(m);
  for (i64 i = 0; i < m; i++)
    cin >> b[i];
  sort(b.begin(), b.end(), greater<i64>());
  if (suma <= e)
  {
    cout << "Yes\n0" << endl;
    return 0;
  }
  i64 sumb = e;
  for (i64 i = 0; i < k; i++)
  {
    sumb += b[i];
    if (suma <= sumb)
    {
      cout << "Yes\n"
           << i + 1 << endl;
      return 0;
    }
  }
  sort(a.begin(), a.end());
  suma = 0;
  cerr << sumb << endl;
  for (i64 i = 0; i < n; i++)
  {
    if (sumb < suma + a[i])
    {
      cout << "No\n"
           << i << endl;
      return 0;
    }
    suma += a[i];
  }
  cout << "No\n0" << endl;
  return 0;
}
