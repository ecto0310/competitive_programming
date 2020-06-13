// URL: https://atcoder.jp/contests/tokiomarine2020/submissions/14257286
// Date: Sat, 13 Jun 2020 23:27:25 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, K;
  cin >> N >> K;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  vector<i64> tmp(N);
  for (i64 i = 0; i < K; i++)
  {
    for (i64 j = 0; j < N; j++)
    {
      tmp[max(0LL, j - A[j])]++;
      if (j + A[j] + 1 < N)
        tmp[j + A[j] + 1]--;
    }
    for (i64 j = 1; j < N; j++)
      tmp[j] += tmp[j - 1];
    A = tmp;
    tmp = vector<i64>(N);
    bool fin = true;
    for (i64 j = 0; j < N; j++)
      if (A[j] != N)
        fin = false;
    if (fin)
      break;
  }
  for (i64 i = 0; i < N; i++)
    cout << A[i] << " \n"[i + 1 == N];
  return 0;
}
