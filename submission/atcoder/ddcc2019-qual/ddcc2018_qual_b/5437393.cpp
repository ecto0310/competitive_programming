// URL: https://atcoder.jp/contests/ddcc2019-qual/submissions/5437393
// Date: Sat, 18 May 2019 21:07:08 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  if (n % 2 == 0)
    cout << 2 * n / 2 * (n / 2 - 1) << endl;
  else
    cout << 2 * (n - 1) / 2 * ((n - 1) / 2 - 1) + 1 << endl;
  return 0;
}
