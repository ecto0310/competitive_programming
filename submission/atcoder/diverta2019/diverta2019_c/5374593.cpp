// URL: https://atcoder.jp/contests/diverta2019/submissions/5374593
// Date: Sun, 12 May 2019 13:43:46 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<string> s(n);
  for (i64 i = 0; i < n; i++)
    cin >> s[i];
  i64 ans = 0, ea = 0, sb = 0, ba = 0;
  for (i64 i = 0; i < n; i++)
  {
    if (s[i][s[i].size() - 1] == 'A' && s[i][0] == 'B')
      ba++;
    else if (s[i][s[i].size() - 1] == 'A')
      ea++;
    else if (s[i][0] == 'B')
      sb++;
    for (i64 j = 0; j < s[i].size() - 1; j++)
      if (s[i].substr(j, 2) == "AB")
        ans++;
  }
  cout << ans + ba + (0 < ea + sb || ba == 0  ? min(ea, sb) : -1) << endl;
  return 0;
}
