// URL: https://atcoder.jp/contests/past202005-open/submissions/14062241
// Date: Sat, 06 Jun 2020 18:06:38 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<string> a(N);
  for (i64 i = 0; i < N; i++)
    cin >> a[i];
  string ans;
  for (i64 i = 0; i < (N + 1) / 2; i++)
  {
    for (i64 j = 0; j < N; j++)
      for (i64 k = 0; k < N; k++)
      {
        if (a[i][j] == a[N - i - 1][k])
        {
          ans += a[i][j];
          goto ok;
        }
      }
  ok:;
  }
  if (ans.size() == (N + 1) / 2)
  {
    cout << ans;
    reverse(ans.begin(), ans.end());
    cout << ans.substr(N % 2, ans.size() - N % 2) << endl;
  }
  else
    cout << -1 << endl;
  return 0;
}
