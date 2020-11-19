// URL: https://codeforces.com/contest/1256/submission/64229439
// Date: Mon, 04 Nov 2019 22:56:18 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 q;
  cin >> q;
  for (i64 _ = 0; _ < q; _++)
  {
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (i64 i = 0; i < n; i++)
      cin >> a[i];
    for (i64 i = 0; i < n - 1; i++)
    {
      i64 it = 0, m = 1e9;
      for (i64 j = i; j < n; j++)
        if (a[j] < m)
        {
          it = j;
          m = a[j];
        }
      a.insert(a.begin() + i, a[it]);
      a.erase(a.begin() + it + 1);
      if (i == it)
        i = it;
      else
        i = it - 1;
    }
    for (i64 i = 0; i < n; i++)
      cout << a[i] << (i + 1 == n ? "\n" : " ");
  }
  return 0;
}
