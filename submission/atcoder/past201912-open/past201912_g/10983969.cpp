// URL: https://atcoder.jp/contests/past201912-open/submissions/10983969
// Date: Wed, 18 Mar 2020 19:09:55 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<vector<i64>> a(N, vector<i64>(N));
  for (i64 i = 0; i < N; i++)
    for (i64 j = i + 1; j < N; j++)
    {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  i64 ans = -1e9;
  i64 l = 1;
  for (i64 i = 0; i < N; i++)
    l *= 3;
  for (i64 i = 0; i < l; i++)
  {
    i64 tmp = i;
    vector<i64> g;
    for (i64 j = 0; j < N; j++)
    {
      g.push_back(tmp % 3);
      tmp /= 3;
    }
    i64 t = 0;
    for (i64 i = 0; i < N; i++)
      for (i64 j = i + 1; j < N; j++)
        if (g[i] == g[j])
          t += a[i][j];
    ans = max(ans, t);
  }
  cout << ans << endl;
  return 0;
}
