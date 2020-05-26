// URL: https://atcoder.jp/contests/abc030/submissions/3828300
// Date: Thu, 20 Dec 2018 21:17:33 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << ((double)b / a > (double)d / c ? "TAKAHASHI" : (double)b / a == (double)d / c ? "DRAW" : "AOKI") << endl;

  return 0;
}
