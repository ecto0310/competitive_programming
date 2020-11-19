// URL: https://atcoder.jp/contests/abc170/submissions/14294680
// Date: Sun, 14 Jun 2020 21:05:11 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 X, N;
  cin >> X >> N;
  vector<i64> p(N);
  for (i64 i = 0; i < N; i++)
    cin >> p[i];
  i64 ans = 1e9;
  for (i64 i = X - 101; i < X + 101; i++)
    if (abs(i - X) < abs(ans - X))
    {
      bool ok = true;
      for (i64 j = 0; j < N; j++)
        if (i == p[j])
          ok = false;
      if (ok)
        ans = i;
    }
  cout << ans << endl;
  return 0;
}
