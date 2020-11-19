// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3637279
// Date: Sat, 08 Jun 2019 22:18:00 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  while (true)
  {
    i64 n;
    cin >> n;
    if (n == 0)
      break;
    vector<i64> a(n);
    i64 sum = 0;
    for (i64 i = 0; i < n; i++)
    {
      cin >> a[i];
      sum += a[i];
    }
    i64 ans = 0;
    for (i64 i = 0; i < n; i++)
      if (a[i] <= sum / n)
        ans++;
    cout << ans << endl;
  }
  return 0;
}
