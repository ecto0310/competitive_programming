// URL: https://atcoder.jp/contests/past202005-open/submissions/14062185
// Date: Sat, 06 Jun 2020 18:05:40 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<i64> a(M);
  for (i64 i = 0; i < M; i++)
    cin >> a[i];
  vector<i64> c(N);
  for (i64 i = 0; i < M; i++)
  {
    i64 it = upper_bound(c.begin(), c.end(), -a[i]) - c.begin();
    if (it != N)
    {
      cout << it + 1 << endl;
      c[it] = -a[i];
    }
    else
      cout << -1 << endl;
  }
  return 0;
}
