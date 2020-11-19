// URL: https://atcoder.jp/contests/past202005-open/submissions/14062170
// Date: Sat, 06 Jun 2020 18:05:24 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, Q;
  cin >> N >> Q;
  vector<i64> bot(N + 1), root(N + 1);
  for (i64 i = 1; i <= N; i++)
  {
    bot[i] = i;
    root[i] = -i;
  }
  for (i64 i = 0; i < Q; i++)
  {
    i64 f, t, x;
    cin >> f >> t >> x;
    i64 r = root[x];
    root[x] = bot[t];
    bot[t] = bot[f];
    bot[f] = r;
  }
  vector<i64> ans(N + 1, -1);
  for (i64 i = 1; i <= N; i++)
  {
    i64 now = bot[i];
    while (0 < now)
    {
      ans[now] = i;
      now = root[now];
    }
  }
  for (i64 i = 1; i <= N; i++)
    cout << ans[i] << endl;
  return 0;
}
