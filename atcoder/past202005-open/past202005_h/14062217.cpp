// URL: https://atcoder.jp/contests/past202005-open/submissions/14062217
// Date: Sat, 06 Jun 2020 18:06:11 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, L;
  cin >> N >> L;
  set<i64> x;
  for (i64 i = 0; i < N; i++)
  {
    i64 t;
    cin >> t;
    x.insert(t);
  }
  i64 T[3];
  cin >> T[0] >> T[1] >> T[2];
  vector<i64> ans(L + 1, 1e9);
  ans[0] = 0;
  for (i64 i = 0; i < L; i++)
  {
    ans[i + 1] = min(ans[i + 1], ans[i] + T[0] + (x.count(i + 1) == 1 ? T[2] : 0));
    if (i + 2 <= L)
    {
      ans[i + 2] = min(ans[i + 2], ans[i] + T[0] + T[1] + (x.count(i + 2) == 1 ? T[2] : 0));
    }
    else
    {
      if (i + 1 == L)
        ans[i + 1] = min(ans[i + 1], ans[i] + T[0] / 2 + T[1] / 2);
    }
    if (i + 4 <= L)
    {
      ans[i + 4] = min(ans[i + 4], ans[i] + T[0] + T[1] * 3 + (x.count(i + 4) == 1 ? T[2] : 0));
    }
    else
    {
      if (i + 1 == L)
        ans[i + 1] = min(ans[i + 1], ans[i] + T[0] / 2 + T[1] / 2);
      if (i + 2 == L)
        ans[i + 2] = min(ans[i + 2], ans[i] + T[0] / 2 + T[1] / 2 * 3);
      if (i + 3 == L)
        ans[i + 3] = min(ans[i + 3], ans[i] + T[0] / 2 + T[1] / 2 * 5);
    }
  }
  cout << ans[L] << endl;
  return 0;
}
