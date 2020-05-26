// URL: https://atcoder.jp/contests/abc133/submissions/6272141
// Date: Sun, 07 Jul 2019 21:10:31 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, d;
  cin >> n >> d;
  i64 ans = 0;
  vector<vector<i64>> x(n, vector<i64>(d));
  for (i64 i = 0; i < n; i++)
    for (i64 j = 0; j < d; j++)
      cin >> x[i][j];
  for (i64 i = 0; i < n; i++)
    for (i64 j = i + 1; j < n; j++)
    {
      i64 sum = 0;
      for (i64 k = 0; k < d; k++)
        sum += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
      if ((int)sqrt(sum) * sqrt(sum) == sum)
        ans++;
    }
  cout << ans << endl;
  return 0;
}
