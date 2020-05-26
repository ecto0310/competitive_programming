// URL: https://atcoder.jp/contests/code-festival-2018-quala/submissions/4406953
// Date: Thu, 28 Feb 2019 00:35:27 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M, A, B;
  cin >> N >> M >> A >> B;
  vector<bool> a(N, false);
  for (int i = 0; i < M; i++)
  {
    int L, R;
    cin >> L >> R;
    for (int j = L - 1; j <= R - 1; j++)
      a[j] = true;
  }
  int ans = 0;
  for (int i = 0; i < N; i++)
    if (a[i])
      ans += A;
    else
      ans += max(A, B);
  cout << ans << endl;

  return 0;
}
