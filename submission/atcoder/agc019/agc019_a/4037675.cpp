// URL: https://atcoder.jp/contests/agc019/submissions/4037675
// Date: Fri, 18 Jan 2019 23:10:53 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  long long Q, H, S, D, N;
  cin >> Q >> H >> S >> D >> N;
  S = min(S, 2 * min(H, Q * 2));
  if (S * 2 < D)
    cout << N * S << endl;
  else
    cout << N / 2 * D + N % 2 * S << endl;

  return 0;
}
