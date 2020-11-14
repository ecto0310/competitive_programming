// URL: http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=4992082
// Date: Sat, 14 Nov 2020 22:14:38 +0900
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, xt;
  cin >> N >> xt;
  vector<i64> x(N);
  for (i64 i = 0; i < N; i++)
    cin >> x[i];
  cout << min(abs(xt - *min_element(x.begin(), x.end())), abs(xt - *max_element(x.begin(), x.end()))) + (*max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end())) << endl;
  return 0;
}
