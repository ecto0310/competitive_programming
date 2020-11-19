// URL: https://atcoder.jp/contests/nikkei2019-2-qual/submissions/8658123
// Date: Tue, 26 Nov 2019 15:42:29 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  if (n % 2 == 0)
    cout << n / 2 - 1 << endl;
  else
    cout << n / 2 << endl;
  return 0;
}
