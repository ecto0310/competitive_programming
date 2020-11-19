// URL: https://atcoder.jp/contests/tkppc3/submissions/6546641
// Date: Sat, 27 Jul 2019 00:10:02 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 h, w, q;
  cin >> h >> w >> q;
  vector<i64> a(h), b(w);
  for (i64 i = 0; i < h; i++)
  {
    cin >> a[i];
    if (i % 2 == 1)
      a[i] *= -1;
  }
  for (i64 i = 0; i < w; i++)
  {
    cin >> b[i];
    if (i % 2 == 1)
      b[i] *= -1;
  }
  vector<i64> suma(h + 1), sumb(w + 1);
  for (i64 i = 0; i < h; i++)
    suma[i + 1] = suma[i] + a[i];
  for (i64 i = 0; i < w; i++)
    sumb[i + 1] = sumb[i] + b[i];
  while (q--)
  {
    i64 px, py, qx, qy;
    cin >> py >> px >> qy >> qx;
    cout << (suma[qy] - suma[py - 1]) * (sumb[qx] - sumb[px - 1]) << endl;
  }

  return 0;
}
