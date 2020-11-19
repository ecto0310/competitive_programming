// URL: https://atcoder.jp/contests/abc130/submissions/5954106
// Date: Sun, 16 Jun 2019 21:03:25 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, x;
  cin >> n >> x;
  vector<i64> l(n);
  for (i64 i = 0; i < n; i++)
    cin >> l[i];
  i64 d = 0;
  for (i64 i = 0; i < n; i++)
  {
    d += l[i];
    if (x < d)
    {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << n + 1 << endl;
  return 0;
}
