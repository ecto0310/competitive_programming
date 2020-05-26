// URL: https://atcoder.jp/contests/abc137/submissions/7365624
// Date: Fri, 06 Sep 2019 22:17:05 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 k, x;
  cin >> k >> x;
  for (i64 i = x - k + 1; i < k + x; i++)
    cout << i << (i + 1 == k + x ? "\n" : " ");
  return 0;
}
