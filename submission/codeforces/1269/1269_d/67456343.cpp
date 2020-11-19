// URL: https://codeforces.com/contest/1269/submission/67456343
// Date: Mon, 23 Dec 2019 16:04:22 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  i64 w = 0, b = 0;
  for (i64 i = 0; i < n; i++)
    if (i % 2 == 0)
    {
      w += a[i] / 2 + a[i] % 2;
      b += a[i] / 2;
    }
    else
    {
      b += a[i] / 2 + a[i] % 2;
      w += a[i] / 2;
    }
  cout << min(w, b) << endl;
  return 0;
}
