// URL: https://atcoder.jp/contests/judge-update-202004/submissions/11589022
// Date: Sun, 05 Apr 2020 21:47:27 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, Q;
  cin >> N >> Q;
  vector<i64> A(N), S(Q);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  for (i64 i = 0; i < Q; i++)
    cin >> S[i];
  for (i64 i = 1; i < N; i++)
    A[i] = gcd(A[i], A[i - 1]);
  for (i64 i = 0; i < Q; i++)
  {
    i64 l = -1, r = N;
    while (1 < r - l)
    {
      i64 mid = (l + r) / 2;
      if (gcd(A[mid], S[i]) != 1)
        l = mid;
      else
        r = mid;
    }
    if (l == N - 1)
    {
      cout << gcd(A[N - 1], S[i]) << endl;
    }
    else
      cout << r + 1 << endl;
  }
  return 0;
}
