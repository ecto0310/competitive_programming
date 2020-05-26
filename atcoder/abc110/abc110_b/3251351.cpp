// URL: https://atcoder.jp/contests/abc110/submissions/3251351
// Date: Sun, 23 Sep 2018 21:08:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  int tx = -100, ty = 100;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    cin >> tmp;
    tx = max(tx, tmp);
  }
  for (int i = 0; i < m; i++)
  {
    int tmp;
    cin >> tmp;
    ty = min(ty, tmp);
  }
  if (ty > tx && x < ty && ty < y)
    cout << "No War" << endl;
  else
    cout << "War" << endl;

  return 0;
}
