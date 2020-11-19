// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3925491
// Date: Sat, 12 Oct 2019 15:26:12 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const i64 MOD = 1e9 + 7;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> p(n);
  for (i64 i = 0; i < n; i++)
    cin >> p[i];
  set<i64> d;
  for (i64 i = 1; i < (1LL << n); i++)
  {
    i64 g = -1;
    for (i64 j = 0; j < n; j++)
      if (i & (1 << j))
      {
        if (g == -1)
          g = p[j];
        else
          g = g * p[j] / __gcd(g, p[j]);
      }
    d.insert(g);
  }
  cout << d.size() << endl;
  return 0;
}
