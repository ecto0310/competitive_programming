// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3860076
// Date: Wed, 11 Sep 2019 16:12:29 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 x;
  cin >> x;
  string ans[7] = {"thu", "fri", "sat", "sun", "mon", "tue", "wed"};
  cout << ans[x % 7] << endl;
  return 0;
}
