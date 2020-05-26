// URL: https://atcoder.jp/contests/tenka1-2012-qualC/submissions/12971708
// Date: Sat, 09 May 2020 12:50:32 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 n;
  cin >> n;
  vector<bool> ok(n + 1, true);
  ok[0] = ok[1] = false;
  for (i64 i = 2; i <= sqrt(n); i++)
    if (ok[i])
      for (i64 j = i * 2; j <= n; j += i)
        ok[j] = false;
  i64 ans = 0;
  for (i64 i = 0; i < n; i++)
    if (ok[i])
      ans++;
  cout << ans << endl;
  return 0;
}
