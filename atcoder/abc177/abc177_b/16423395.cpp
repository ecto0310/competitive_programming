// URL: https://atcoder.jp/contests/abc177/submissions/16423395
// Date: Mon, 31 Aug 2020 19:37:43 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string S, T;
  cin >> S >> T;
  i64 ans = 1e9;
  for (i64 i = 0; i < S.size() - T.size() + 1; i++)
  {
    i64 tmp = 0;
    for (i64 j = 0; j < T.size(); j++)
      if (S[i + j] != T[j])
        tmp++;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
