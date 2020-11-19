// URL: https://atcoder.jp/contests/abc178/submissions/16730371
// Date: Mon, 14 Sep 2020 01:36:42 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> x(N), y(N);
  for (i64 i = 0; i < N; i++)
    cin >> x[i] >> y[i];
  for (i64 i = 0; i < N; i++)
  {
    i64 tx = x[i], ty = y[i];
    x[i] = tx + ty;
    y[i] = tx - ty;
  }
  cout << max(*max_element(x.begin(), x.end()) - *min_element(x.begin(), x.end()), *max_element(y.begin(), y.end()) - *min_element(y.begin(), y.end())) << endl;
  return 0;
}
