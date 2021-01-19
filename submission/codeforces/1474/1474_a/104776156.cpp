// URL: https://codeforces.com/contest/1474/submission/104776156
// Date: Tue, 19 Jan 2021 23:44:03 +0900
// Language: GNU C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 t;
  cin >> t;
  for (i64 _ = 0; _ < t; _++)
  {
    i64 n;
    string b;
    cin >> n >> b;
    string ans;
    char last = '-';
    for (i64 i = 0; i < n; i++)
    {
      if (b[i] + 1 == last)
      {
        ans += "0";
        last = b[i];
      }
      else
      {
        ans += "1";
        last = b[i] + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
