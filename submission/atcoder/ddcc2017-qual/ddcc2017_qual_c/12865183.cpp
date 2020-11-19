// URL: https://atcoder.jp/contests/ddcc2017-qual/submissions/12865183
// Date: Tue, 05 May 2020 22:53:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N, C;
  cin >> N >> C;
  vector<i64> L(N);
  for (i64 i = 0; i < N; i++)
    cin >> L[i];
  sort(L.begin(), L.end());
  i64 ans = N, now = 0;
  for (i64 i = N - 1; 0 <= i; i--)
    if (now < i && L[i] + L[now] < C)
    {
      now++;
      ans--;
    }
  cout << ans << endl;
  return 0;
}
