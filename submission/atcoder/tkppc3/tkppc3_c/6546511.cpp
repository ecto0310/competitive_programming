// URL: https://atcoder.jp/contests/tkppc3/submissions/6546511
// Date: Fri, 26 Jul 2019 23:57:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, p;
  cin >> n >> p;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  i64 s = 1, r = 0;
  bool ans = false;
  for (i64 l = 0; l < n; l++)
  {
    while (s * a[r] <= p && r < n)
    {
      s *= a[r];
      r++;
    }
    if (s == p)
      ans = true;
    if (r == l)
      r++;
    else
      s /= a[l];
  }
  if (ans)
    cout << "Yay!" << endl;
  else
    cout << ":(" << endl;
  return 0;
}
