// URL: https://atcoder.jp/contests/abc157/submissions/10439907
// Date: Sun, 01 Mar 2020 21:20:34 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<i64> s(M), c(M);
  for (i64 i = 0; i < M; i++)
    cin >> s[i] >> c[i];
  vector<i64> ans(N, -1);
  for (i64 i = 0; i < M; i++)
    if (ans[s[i] - 1] == -1)
      ans[s[i] - 1] = c[i];
    else if (ans[s[i] - 1] != c[i])
    {
      cout << -1 << endl;
      return 0;
    }
  if (1 < N && ans[0] == 0)
  {
    cout << -1 << endl;
    return 0;
  }
  if (N == 1 && ans[0] == -1)
    cout << 0 << endl;
  else
  {
    for (i64 i = 0; i < N; i++)
      if (i == 0)
        cout << (ans[i] == -1 ? 1 : ans[i]);
      else
        cout << max(0LL, ans[i]);
    cout << endl;
  }
  return 0;
}
