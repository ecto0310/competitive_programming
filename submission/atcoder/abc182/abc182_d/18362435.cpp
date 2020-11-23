// URL: https://atcoder.jp/contests/abc182/submissions/18362435
// Date: Mon, 23 Nov 2020 14:09:00 +0900
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
  i64 ans = 0, now = 0, sum = 0, m = 0;
  for (i64 i = 0; i < N; i++)
  {
    sum += A[i];
    m = max(sum, m);
    ans = max(ans, now + m);
    now += sum;
  }
  cout << ans << endl;
  return 0;
}
