// URL: https://atcoder.jp/contests/abc175/submissions/15908077
// Date: Sat, 15 Aug 2020 21:01:44 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string s;
  cin >> s;
  i64 ans = 0, now = 0;
  for (i64 i = 0; i < 3; i++)
    if (s[i] == 'R')
    {
      now++;
      ans = max(ans, now);
    }
    else
      now = 0;
  cout << ans << endl;
  return 0;
}
