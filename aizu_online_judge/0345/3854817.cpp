// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3854817
// Date: Mon, 09 Sep 2019 14:06:26 +0900
// Language: C++14
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 e[4];
  cin >> e[0] >> e[1] >> e[2] >> e[3];
  sort(e, e + 4);
  if (e[0] == e[1] && e[2] == e[3])
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
