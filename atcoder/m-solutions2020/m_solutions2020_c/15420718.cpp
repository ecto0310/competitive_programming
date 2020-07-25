// URL: https://atcoder.jp/contests/m-solutions2020/submissions/15420718
// Date: Sat, 25 Jul 2020 21:08:52 +0900
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
  for (i64 i = K; i < N; i++)
    if (A[i] <= A[i - K])
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  return 0;
}
