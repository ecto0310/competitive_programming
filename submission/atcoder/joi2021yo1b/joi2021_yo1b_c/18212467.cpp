// URL: https://atcoder.jp/contests/joi2021yo1b/submissions/18212467
// Date: Thu, 19 Nov 2020 07:46:22 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"
 
int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  i64 m = max_element(A.begin(), A.end()) - A.begin();
  i64 ans[2] = {};
  for (i64 i = 0; i < N; i++)
    if (i < m)
      ans[0] += A[i];
    else if (m < i)
      ans[1] += A[i];
  cout << ans[0] << endl
       << ans[1] << endl;
  return 0;
}
