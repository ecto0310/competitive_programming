// URL: https://codeforces.com/contest/1077/submission/72478155
// Date: Thu, 05 Mar 2020 09:05:25 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
 
int main()
{
  i64 t;
  cin >> t;
  for (i64 i = 0; i < t; i++)
  {
    i64 a, b, k, ans = 0;
    cin >> a >> b >> k;
    if (k % 2 == 0)
      cout << a * (k / 2) - b * (k / 2) << endl;
    else
      cout << a * ((k + 1) / 2) - b * (k / 2) << endl;
  }
  return 0;
}
