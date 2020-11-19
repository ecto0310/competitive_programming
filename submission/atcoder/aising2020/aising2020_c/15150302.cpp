// URL: https://atcoder.jp/contests/aising2020/submissions/15150302
// Date: Sat, 11 Jul 2020 21:05:12 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> ans(N + 1);
  for (i64 x = 1; x * x <= N; x++)
    for (i64 y = 1; y * y <= N; y++)
      for (i64 z = 1; z * z <= N; z++)
      {
        i64 t = x * x + y * y + z * z + x * y + y * z + z * x;
        if (t <= N)
          ans[t]++;
      }
  for (i64 i = 1; i <= N; i++)
    cout << ans[i] << endl;
  return 0;
}
