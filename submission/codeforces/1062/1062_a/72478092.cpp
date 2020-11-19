// URL: https://codeforces.com/contest/1062/submission/72478092
// Date: Thu, 05 Mar 2020 09:01:59 +0900
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
  i64 ans = 0, cnt = 0;
  for (i64 i = 0; i < n; i++)
    if ((i < n - 1 && a[i] == i + 1 && a[i + 1] == i + 2) || (0 < i && i < n - 1 && a[i - 1] == a[i] - 1 && a[i + 1] == a[i] + 1) || (0 < i && a[i - 1] == 1000 - n + i && a[i] == 1000 - n + i + 1))
      cnt++;
    else
    {
      ans = max(ans, cnt);
      cnt = 0;
    }
  cout << max(ans, cnt) << endl;
  return 0;
}
