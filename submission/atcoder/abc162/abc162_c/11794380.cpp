// URL: https://atcoder.jp/contests/abc162/submissions/11794380
// Date: Sun, 12 Apr 2020 21:03:11 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 K;
  cin >> K;
  i64 ans = 0;
  for (i64 i = 1; i <= K; i++)
    for (i64 j = 1; j <= K; j++)
      for (i64 k = 1; k <= K; k++)
        ans += gcd(i, gcd(j, k));
  cout << ans << endl;
  return 0;
}
