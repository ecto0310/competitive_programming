// URL: https://atcoder.jp/contests/xmascon19/submissions/9119879
// Date: Tue, 24 Dec 2019 23:21:49 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<string> a(n), b(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i] >> b[i];
  bool ans = false;
  for (i64 i = 0; i < n; i++)
  {
    i64 cnt = 0;
    for (i64 j = 0; j < a[i].size(); j++)
      if (a[i][j] == b[i][cnt])
      {
        cnt++;
        if (cnt == b[i].size())
        {
          ans = true;
          break;
        }
      }
  }
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
