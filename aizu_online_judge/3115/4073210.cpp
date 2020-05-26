// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4073210
// Date: Wed, 25 Dec 2019 09:31:14 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  vector<i64> a(n);
  for (i64 i = 0; i < n; i++)
    cin >> a[i];
  set<i64> s;
  for (i64 i = 0; i < n; i++)
    s.insert(a[i]);
  cout << s.size() << endl;
  return 0;
}
