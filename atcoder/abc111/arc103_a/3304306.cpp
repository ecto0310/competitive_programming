// URL: https://atcoder.jp/contests/abc111/submissions/3304306
// Date: Sun, 30 Sep 2018 00:22:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int g[100001], k[100001];

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int gm, gmt = 0, km, kmt = 0;
  for (int i = 0; i < n; i++)
    if (i % 2 == 0)
    {
      g[v[i]]++;
      if (g[v[i]] > gmt)
      {
        gmt = g[v[i]];
        gm = v[i];
      }
    }
    else
    {
      k[v[i]]++;
      if (k[v[i]] > kmt)
      {
        kmt = k[v[i]];
        km = v[i];
      }
    }
  sort(g, g + 100001, greater<int>());
  sort(k, k + 100001, greater<int>());
  if (gm == km)
    cout << (g[1] > k[1] ? n - k[0] - g[1] : n - g[0] - k[1]) << endl;
  else
    cout << n - g[0] - k[0] << endl;

  return 0;
}
