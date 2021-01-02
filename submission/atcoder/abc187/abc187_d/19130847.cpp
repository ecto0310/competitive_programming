// URL: https://atcoder.jp/contests/abc187/submissions/19130847
// Date: Sat, 02 Jan 2021 21:16:49 +0900
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
  i64 Asum = 0;
  for (i64 i = 0; i < N; i++)
    Asum += A[i];
  vector<i64> tmp(N);
  for (i64 i = 0; i < N; i++)
    tmp[i] = A[i] * 2 + B[i];
  sort(tmp.rbegin(), tmp.rend());
  for (i64 i = 0; i < N; i++)
  {
    Asum -= tmp[i];
    if (Asum < 0)
    {
      cout << i + 1 << endl;
      return 0;
    }
  }
  return 0;
}
