// URL: https://atcoder.jp/contests/judge-update-202004/submissions/11585004
// Date: Sun, 05 Apr 2020 21:14:29 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 a[3];
  cin >> a[0] >> a[1] >> a[2];
  i64 N = a[0] + a[1] + a[2];
  vector<i64> n(N);
  for (i64 i = 0; i < N; i++)
    n[i] = i;
  i64 ans = 0;
  do
  {
    bool ok = true;
    vector<i64> b[3];
    i64 tmp = 0;
    for (i64 i = 0; i < 3; i++)
    {
      b[i].resize(3, 1e9);
      for (i64 j = 0; j < a[i]; j++)
      {
        b[i][j] = n[tmp];
        tmp++;
      }
    }
    for (i64 i = 0; i < 3; i++)
      for (i64 j = 0; j < 3; j++)
      {
        if (i != 0 && b[i][j] < b[i - 1][j])
          ok = false;
        if (j != 0 && b[i][j] < b[i][j - 1])
          ok = false;
      }
    if (ok)
      ans++;
  } while (next_permutation(n.begin(), n.end()));
  cout << ans << endl;
  return 0;
}
