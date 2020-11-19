// URL: https://atcoder.jp/contests/abc144/submissions/8177042
// Date: Sun, 27 Oct 2019 22:42:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 n;
  cin >> n;
  string ans = "No";
  for (i64 i = 1; i < 10; i++)
    for (i64 j = 1; j < 10; j++)
      if (i * j == n)
        ans = "Yes";
  cout << ans << endl;
  return 0;
}
