// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3901624
// Date: Tue, 01 Oct 2019 13:00:53 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 x, y;
  cin >> x >> y;
  i64 px[2] = {0, 1};
  i64 py[2] = {0, 1};
  if (x == 0 && y == 0)
  {
    cout << 1 << endl;
    return 0;
  }
  for (i64 i = 0;; i++)
  {
    if (i % 4 == 0)
    {
      px[1] += abs(py[1] - py[0]);
      if (px[0] <= x && x < px[1] && py[0] <= y && y < py[1])
      {
        cout << (i + 1) % 3 + 1 << endl;
        return 0;
      }
    }
    else if (i % 4 == 1)
    {
      py[1] += abs(px[1] - px[0]);
      if (px[0] <= x && x < px[1] && py[0] <= y && y < py[1])
      {
        cout << (i + 1) % 3 + 1 << endl;
        return 0;
      }
    }
    else if (i % 4 == 2)
    {
      px[0] -= abs(py[1] - py[0]);
      if (px[0] <= x && x < px[1] && py[0] <= y && y < py[1])
      {
        cout << (i + 1) % 3 + 1 << endl;
        return 0;
      }
    }
    else
    {
      py[0] -= abs(px[1] - px[0]);
      if (px[0] <= x && x < px[1] && py[0] <= y && y < py[1])
      {
        cout << (i + 1) % 3 + 1 << endl;
        return 0;
      }
    }
  }
  return 0;
}
