// URL: https://atcoder.jp/contests/code-festival-2018-qualb/submissions/5437927
// Date: Sat, 18 May 2019 21:48:14 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<vector<i64>> a(n, vector<i64>(n, 0));
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < n; j++)
      if ((i + 2 * j) % 5 == 0)
      {
        a[i][j] = 3;
        if (0 <= i - 1)
          a[i - 1][j] = 1;
        if (i + 1 < n)
          a[i + 1][j] = 1;
        if (0 <= j - 1)
          a[i][j - 1] = 1;
        if (j + 1 < n)
          a[i][j + 1] = 1;
      }
  for (i64 i = 0; i < n; i++)
  {
    for (i64 j = 0; j < n; j++)
      if (a[i][j] == 0 || a[i][j] == 3)
        cout << "X";
      else
        cout << ".";
    cout << endl;
  }
  return 0;
}
