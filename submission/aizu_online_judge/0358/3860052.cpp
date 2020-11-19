// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3860052
// Date: Wed, 11 Sep 2019 16:09:18 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 m, f, b;
  cin >> m >> f >> b;
  if (m + f < b)
    cout << "NA" << endl;
  else
    cout << max(0LL, b - m) << endl;
  return 0;
}
