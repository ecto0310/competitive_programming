// URL: https://atcoder.jp/contests/past201912-open/submissions/10797797
// Date: Fri, 13 Mar 2020 19:13:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, Q;
  cin >> N >> Q;
  vector<string> ans(N, string(N, 'N'));
  for (i64 _ = 0; _ < Q; _++)
  {
    i64 t;
    cin >> t;
    if (t == 1)
    {
      i64 a, b;
      cin >> a >> b;
      a--;
      b--;
      ans[a][b] = 'Y';
    }
    else if (t == 2)
    {
      i64 a;
      cin >> a;
      a--;
      for (i64 i = 0; i < N; i++)
        if (ans[i][a] == 'Y')
          ans[a][i] = 'Y';
    }
    else
    {
      i64 a;
      cin >> a;
      a--;
      string t = ans[a];
      for (i64 i = 0; i < N; i++)
        if (t[i] == 'Y')
          for (i64 j = 0; j < N; j++)
            if (j != a && ans[i][j] == 'Y')
              ans[a][j] = 'Y';
    }
  }
  for (i64 i = 0; i < N; i++)
    cout << ans[i] << endl;
  return 0;
}
