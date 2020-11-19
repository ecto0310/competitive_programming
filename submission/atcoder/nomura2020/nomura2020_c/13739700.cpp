// URL: https://atcoder.jp/contests/nomura2020/submissions/13739700
// Date: Sat, 30 May 2020 22:43:00 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N + 1);
  for (i64 i = 0; i <= N; i++)
    cin >> A[i];
  vector<i64> sum = A;
  for (i64 i = N; 0 < i; i--)
    sum[i - 1] += sum[i];
  i64 ans = 0, node = 1;
  for (i64 i = 0; i < N; i++)
  {
    ans += node;
    if (node - A[i] < 0)
    {
      cout << -1 << endl;
      return 0;
    }
    node = min((node - A[i]) * 2, sum[i + 1]);
  }
  ans += node;
  if (node - A[N] == 0)
    cout << ans << endl;
  else
    cout << -1 << endl;
  return 0;
}
