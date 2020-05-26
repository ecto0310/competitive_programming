// URL: https://atcoder.jp/contests/abc143/submissions/8019174
// Date: Sat, 19 Oct 2019 21:00:56 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 a, b;
  cin >> a >> b;
  cout << max(0LL, a - 2 * b) << endl;
  return 0;
}
