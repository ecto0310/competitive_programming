// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3558369
// Date: Sat, 11 May 2019 13:51:50 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, x;
  cin >> a >> b >> x;
  i64 ans = 1e9;
  for (i64 i = 0; i < 100; i++)
    for (i64 j = 0; j < 100; j++)
    {
      i64 cost = i * a + j * b;
      if (x <= i * 1000 + j * 500)
        ans = min(ans, cost);
    }
  cout << ans << endl;
  return 0;
}
