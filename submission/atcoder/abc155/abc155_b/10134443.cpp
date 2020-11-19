// URL: https://atcoder.jp/contests/abc155/submissions/10134443
// Date: Sun, 16 Feb 2020 21:05:08 +0900
// Language: C++14 (GCC 5.4.1)
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
  bool ans = true;
  for (i64 i = 0; i < n; i++)
    if (a[i] % 2 == 0 && a[i] % 3 != 0 && a[i] % 5 != 0)
      ans = false;
  if (ans)
    cout << "APPROVED" << endl;
  else
    cout << "DENIED" << endl;
  return 0;
}
