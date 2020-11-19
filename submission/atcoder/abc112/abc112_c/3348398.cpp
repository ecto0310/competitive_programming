// URL: https://atcoder.jp/contests/abc112/submissions/3348398
// Date: Sat, 06 Oct 2018 21:36:47 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, x[100], y[100], h[100];
  cin >> n;
  int tx, ty, th = -1;
  for (int i = 0; i < n; i++)
  {
    cin >> x[i] >> y[i] >> h[i];
    if (h[i] > 0)
    {
      tx = x[i];
      ty = y[i];
      th = h[i];
    }
  }
  for (int cx = 0; cx <= 100; cx++)
    for (int cy = 0; cy <= 100; cy++)
    {
      if (th == -1)
      {
        
      }
      else
      {
        int hh = max(th + abs(cx - tx) + abs(cy - ty), 0);
        bool ok = true;
        for (int i = 0; i < n; i++)
          if (max(hh - abs(cx - x[i]) - abs(cy - y[i]), 0) != h[i])
            ok = false;
        if (ok)
        {
          cout << cx << " " << cy << " " << hh << endl;
          return 0;
        }
      }
    }

  return 0;
}
