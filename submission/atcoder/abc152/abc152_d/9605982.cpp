// URL: https://atcoder.jp/contests/abc152/submissions/9605982
// Date: Sun, 19 Jan 2020 20:58:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  i64 cnt[10][10] = {};
  for (i64 i = 1; i <= n; i++)
  {
    string t = to_string(i);
    cnt[t[0] - '0'][t[t.size() - 1] - '0']++;
  }
  i64 ans = 0;
  for (i64 i = 1; i <= n; i++)
  {
    string t = to_string(i);
    ans += cnt[t[t.size() - 1] - '0'][t[0] - '0'];
  }
  cout << ans << endl;
  return 0;
}
