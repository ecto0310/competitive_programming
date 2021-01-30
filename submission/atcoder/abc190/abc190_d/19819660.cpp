// URL: https://atcoder.jp/contests/abc190/submissions/19819660
// Date: Sat, 30 Jan 2021 22:49:00 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  i64 ans = 0;
  for (i64 i = 1;; i++)
  {
    if ((N * 2 / i - i + 1) / 2 <= 0)
      break;
    if (2 * N % i == 0 && (N * 2 / i - i + 1) % 2 == 0)
      ans += 2;
  }
  cout << ans << endl;
  return 0;
}
