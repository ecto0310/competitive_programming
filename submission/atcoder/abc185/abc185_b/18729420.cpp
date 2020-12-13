// URL: https://atcoder.jp/contests/abc185/submissions/18729420
// Date: Sun, 13 Dec 2020 21:09:49 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M, T;
  cin >> N >> M >> T;
  vector<i64> A(M), B(M);
  for (i64 i = 0; i < M; i++)
    cin >> A[i] >> B[i];
  i64 now = N;
  for (i64 i = 0; i < M; i++)
  {
    now -= A[i] - (i == 0 ? 0 : B[i - 1]);
    if (now <= 0)
    {
      cout << "No" << endl;
      return 0;
    }
    now += B[i] - A[i];
    now = min(now, N);
  }
  now -= T - B[M - 1];
  if (now <= 0)
  {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
