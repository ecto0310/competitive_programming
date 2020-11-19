// URL: https://atcoder.jp/contests/abc024/submissions/8989596
// Date: Tue, 17 Dec 2019 15:35:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, d, k;
  cin >> n >> d >> k;
  vector<i64> l(d), r(d), s(k), t(k);
  for (i64 i = 0; i < d; i++)
    cin >> l[i] >> r[i];
  for (i64 i = 0; i < k; i++)
    cin >> s[i] >> t[i];
  for (i64 i = 0; i < k; i++)
  {
    i64 tl = s[i], tr = s[i];
    for (i64 j = 0; j < d; j++)
    {
      if (l[j] <= tl && tl <= r[j])
        tl = l[j];
      if (l[j] <= tr && tr <= r[j])
        tr = r[j];
      if (tl <= t[i] && t[i] <= tr)
      {
        cout << j + 1 << endl;
        break;
      }
    }
  }
  return 0;
}
