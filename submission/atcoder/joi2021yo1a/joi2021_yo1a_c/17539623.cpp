// URL: https://atcoder.jp/contests/joi2021yo1a/submissions/17539623
// Date: Tue, 20 Oct 2020 16:27:46 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<i64> A(N), B(M);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  for (i64 i = 0; i < M; i++)
    cin >> B[i];
  vector<i64> ans;
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  for (i64 i : A)
    if (0 < count(B.begin(), B.end(), i))
      cout << i << endl;
  return 0;
}
