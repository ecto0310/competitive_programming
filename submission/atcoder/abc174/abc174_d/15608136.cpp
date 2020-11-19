// URL: https://atcoder.jp/contests/abc174/submissions/15608136
// Date: Sun, 02 Aug 2020 21:14:32 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  string c;
  cin >> N >> c;
  i64 cnt = 0;
  for (i64 i = 0; i < N; i++)
    if (c[i] == 'R')
      cnt++;
  i64 ans = cnt;
  for (i64 i = 0; i < cnt; i++)
    if (c[i] == 'R')
      ans--;
  cout << ans << endl;
  return 0;
}
