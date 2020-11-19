// URL: https://atcoder.jp/contests/agc014/submissions/4037561
// Date: Fri, 18 Jan 2019 22:58:41 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int A[2], B[2], C[2];
  cin >> A[0] >> B[0] >> C[0];
  if (A[0] % 2 == 0 && A[0] == B[0] && B[0] == C[0])
  {
    cout << -1 << endl;
    return 0;
  }
  int ans = 0;
  for (; A[ans & 1] % 2 == 0 && B[ans & 1] % 2 == 0 && C[ans & 1] % 2 == 0; ans++)
  {
    A[(ans + 1) & 1] = B[ans & 1] / 2 + C[ans & 1] / 2;
    B[(ans + 1) & 1] = A[ans & 1] / 2 + C[ans & 1] / 2;
    C[(ans + 1) & 1] = A[ans & 1] / 2 + B[ans & 1] / 2;
  }
  cout << ans << endl;

  return 0;
}
