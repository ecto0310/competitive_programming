// URL: https://atcoder.jp/contests/abc169/submissions/13885169
// Date: Sun, 31 May 2020 22:50:29 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N), B(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i] >> B[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  if (N % 2 == 0)
    cout << B[N / 2 - 1] + B[N / 2] - (A[N / 2 - 1] + A[N / 2]) + 1 << endl;
  else
    cout << B[N / 2] - A[N / 2] + 1 << endl;
  return 0;
}
