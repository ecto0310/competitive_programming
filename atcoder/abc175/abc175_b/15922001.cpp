// URL: https://atcoder.jp/contests/abc175/submissions/15922001
// Date: Sat, 15 Aug 2020 21:15:29 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> L(N);
  for (i64 i = 0; i < N; i++)
    cin >> L[i];
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
    for (i64 j = i + 1; j < N; j++)
      for (i64 k = j + 1; k < N; k++)
        if (abs(L[j] - L[k]) < L[i] && L[i] < L[j] + L[k] && L[i] != L[j] && L[j] != L[k] && L[k] != L[i])
          ans++;
  cout << ans << endl;
  return 0;
}
