// URL: https://codeforces.com/contest/1077/submission/72478141
// Date: Thu, 05 Mar 2020 09:04:53 +0900
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
  i64 ans = 0;
  for (i64 i = 1; i < n - 1; i++)
    if (a[i - 1] == 1 && a[i] == 0 && a[i + 1] == 1)
    {
      a[i + 1] = 0;
      ans++;
    }
  cout << ans << endl;
  return 0;
}
