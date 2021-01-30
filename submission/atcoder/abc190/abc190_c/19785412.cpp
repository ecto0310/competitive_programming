// URL: https://atcoder.jp/contests/abc190/submissions/19785412
// Date: Sat, 30 Jan 2021 21:10:18 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, M;
  cin >> N >> M;
  vector<i64> A(M), B(M);
  for (i64 i = 0; i < M; i++)
    cin >> A[i] >> B[i];
  i64 K;
  cin >> K;
  vector<i64> C(K), D(K);
  for (i64 i = 0; i < K; i++)
    cin >> C[i] >> D[i];
  i64 ans = 0;
  for (i64 i = 0; i < (1 << K); i++)
  {
    vector<i64> cnt(N + 1);
    for (i64 j = 0; j < K; j++)
      if (i & (1 << j))
        cnt[C[j]]++;
      else
        cnt[D[j]]++;
    i64 tmp = 0;
    for (i64 j = 0; j < M; j++)
      if (cnt[A[j]] != 0 && cnt[B[j]] != 0)
        tmp++;
    ans = max(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
