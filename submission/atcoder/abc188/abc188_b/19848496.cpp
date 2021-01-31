// URL: https://atcoder.jp/contests/abc188/submissions/19848496
// Date: Mon, 01 Feb 2021 00:39:17 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N), B(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  for (i64 i = 0; i < N; i++)
    cin >> B[i];
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
    ans += A[i] * B[i];
  if (ans == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
