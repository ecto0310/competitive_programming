// URL: https://atcoder.jp/contests/abc187/submissions/19122908
// Date: Sat, 02 Jan 2021 21:05:34 +0900
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
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
    for (i64 j = i + 1; j < N; j++)
    {
      if (abs(y[i] - y[j]) <= abs(x[i] - x[j]))
        ans++;
    }
  cout << ans << endl;
  return 0;
}
