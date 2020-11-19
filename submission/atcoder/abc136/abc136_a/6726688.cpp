// URL: https://atcoder.jp/contests/abc136/submissions/6726688
// Date: Mon, 05 Aug 2019 18:16:03 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b, c;
  cin >> a >> b >> c;
  cout << max(0LL, c - a + b) << endl;
  return 0;
}
