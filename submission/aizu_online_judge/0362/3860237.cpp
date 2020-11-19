// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3860237
// Date: Wed, 11 Sep 2019 16:44:12 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> d(n);
  for (i64 i = 0; i < n; i++)
    cin >> d[i];
  bool ans = true;
  for (i64 _ = 0; _ < 2; _++)
  {
    i64 m = 0;
    for (i64 i = 0; i < n - 1; i++)
      if (i * 10 <= m)
        m = max(m, i * 10 + d[i]);
    if (m < (n - 1) * 10)
      ans = false;
    reverse(d.begin(), d.end());
  }
  if (ans)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
