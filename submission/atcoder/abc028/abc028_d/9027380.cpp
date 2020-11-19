// URL: https://atcoder.jp/contests/abc028/submissions/9027380
// Date: Fri, 20 Dec 2019 17:29:09 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  cout << fixed << setprecision(10) << (double)((n - k) * (k - 1) * 6 + (n - 1) * 3 + 1) / n / n / n << endl;
  return 0;
}
