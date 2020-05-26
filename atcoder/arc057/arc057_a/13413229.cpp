// URL: https://atcoder.jp/contests/arc057/submissions/13413229
// Date: Wed, 20 May 2020 01:09:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 A, K;
  cin >> A >> K;
  K++;
  i64 ans = 0;
  if (K == 1)
    ans = 2e12 - A;
  else
  {

    while (A < 2e12)
    {
      A = A * K + 1;
      cerr << A << endl;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
