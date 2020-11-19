// URL: https://atcoder.jp/contests/abc161/submissions/11498136
// Date: Sat, 04 Apr 2020 21:05:33 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  sort(A.rbegin(), A.rend());
  i64 sum = 0;
  for (i64 i = 0; i < N; i++)
    sum += A[i];
  i64 cnt = 0;
  for (i64 i = 0; i < N; i++)
    if (sum <= A[i] * 4 * M)
      cnt++;
  if (M <= cnt)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
