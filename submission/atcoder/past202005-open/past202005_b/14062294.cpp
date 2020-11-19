// URL: https://atcoder.jp/contests/past202005-open/submissions/14062294
// Date: Sat, 06 Jun 2020 18:07:36 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M, Q;
  cin >> N >> M >> Q;
  vector<i64> p(M, N);
  vector<set<i64>> s(N);
  for (i64 i = 0; i < Q; i++)
  {
    i64 t;
    cin >> t;
    if (t == 1)
    {
      i64 n;
      cin >> n;
      i64 ans = 0;
      for (i64 i : s[n - 1])
        ans += p[i];
      cout << ans << endl;
    }
    else
    {
      i64 n, m;
      cin >> n >> m;
      p[m - 1]--;
      s[n - 1].insert(m - 1);
    }
  }
  return 0;
}
