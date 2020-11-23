// URL: https://atcoder.jp/contests/abc182/submissions/18362356
// Date: Mon, 23 Nov 2020 14:04:35 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string N;
  cin >> N;
  i64 size = N.size();
  i64 ans = size;
  for (i64 i = 0; i < (1 << size); i++)
  {
    i64 t = 0, cnt = 0;
    ;
    for (i64 j = 0; j < size; j++)
      if ((i >> j) & 1)
      {
        t *= 10;
        t += N[j] - '0';
      }
      else
        cnt++;

    if (t % 3 == 0)
      ans = min(ans, cnt);
  }
  if (ans == size)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
