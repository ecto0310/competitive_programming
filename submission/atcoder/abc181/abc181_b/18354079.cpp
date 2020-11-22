// URL: https://atcoder.jp/contests/abc181/submissions/18354079
// Date: Mon, 23 Nov 2020 01:45:30 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
  {
    i64 A, B;
    cin >> A >> B;
    ans += B * (B + 1) / 2 - A * (A - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
