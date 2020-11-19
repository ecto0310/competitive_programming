// URL: https://atcoder.jp/contests/diverta2019-2/submissions/5917739
// Date: Sat, 15 Jun 2019 21:01:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n, k;
  cin >> n >> k;
  cout << (k == 1 ? 0 : n - k) << endl;
  return 0;
}
