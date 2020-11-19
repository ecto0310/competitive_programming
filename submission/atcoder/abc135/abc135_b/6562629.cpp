// URL: https://atcoder.jp/contests/abc135/submissions/6562629
// Date: Sat, 27 Jul 2019 21:04:23 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> p(n);
  for (i64 i = 0; i < n; i++)
    cin >> p[i];
  vector<i64> tmp = p;
  sort(p.begin(), p.end());
  bool ans = (tmp == p);
  for (i64 i = 0; i < n; i++)
    for (i64 j = i + 1; j < n; j++)
    {
      swap(p[i], p[j]);
      if (p == tmp)
        ans = true;
      swap(p[i], p[j]);
    }
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
