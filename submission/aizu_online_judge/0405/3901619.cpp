// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3901619
// Date: Tue, 01 Oct 2019 12:58:57 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  if (65 <= n && n <= 90)
    cout << 1 << endl;
  else if (97 <= n && n <= 122)
    cout << 2 << endl;
  else
    cout << 0 << endl;
  return 0;
}
