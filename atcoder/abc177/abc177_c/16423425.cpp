// URL: https://atcoder.jp/contests/abc177/submissions/16423425
// Date: Mon, 31 Aug 2020 19:40:22 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const i64 MOD = 1e9 + 7;

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  i64 sum = 0;
  for (i64 i = 0; i < N; i++)
    sum += A[i];
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
  {
    sum -= A[i];
    (ans += sum % MOD * A[i]) %= MOD;
  }
  cout << ans << endl;
  return 0;
}
