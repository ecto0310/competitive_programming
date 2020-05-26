// URL: https://atcoder.jp/contests/nikkei2019-ex/submissions/4311128
// Date: Mon, 18 Feb 2019 16:11:56 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  int ans = 0;
  while (pow(ans + 1, 2) <= N)
    ans++;
  cout << ans << endl;

  return 0;
}
