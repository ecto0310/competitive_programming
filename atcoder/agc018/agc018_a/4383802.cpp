// URL: https://atcoder.jp/contests/agc018/submissions/4383802
// Date: Mon, 25 Feb 2019 16:47:05 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  int g = A[0], m = A[0];
  for (int i = 1; i < N; i++)
  {
    g = __gcd(g, A[i]);
    m = max(m, A[i]);
  }
  if (K <= m && K % g == 0)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;

  return 0;
}
