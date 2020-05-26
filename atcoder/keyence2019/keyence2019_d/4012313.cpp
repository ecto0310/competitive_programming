// URL: https://atcoder.jp/contests/keyence2019/submissions/4012313
// Date: Mon, 14 Jan 2019 11:49:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(M);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  for (int i = 0; i < M; i++)
    cin >> B[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  long long ans = 1;
  int Nu = N, Mu = M;
  for (int i = N * M; 0 < i; i--)
    if (A[Nu - 1] == i && B[Mu - 1] == i && 0 < N * M)
    {
      Nu--;
      Mu--;
    }
    else if (A[Nu - 1] == i && 0 < N)
    {
      ans = (ans * (M - Mu)) % mod;
      Nu--;
    }
    else if (B[Mu - 1] == i && 0 < M)
    {
      ans = (ans * (N - Nu)) % mod;
      Mu--;
    }
    else
      ans = (ans * ((N - Nu) * (M - Mu) - (N * M - i))) % mod;
  cout << ans << endl;

  return 0;
}
