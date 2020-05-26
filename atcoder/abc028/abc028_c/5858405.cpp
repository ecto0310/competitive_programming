// URL: https://atcoder.jp/contests/abc028/submissions/5858405
// Date: Sun, 09 Jun 2019 23:15:00 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
      i64 a, b, c, d, e;
      cin >> a >> b >> c >> d >> e;
      cout << max(a + d + e, b + c + e) << endl;
      return 0;
}
