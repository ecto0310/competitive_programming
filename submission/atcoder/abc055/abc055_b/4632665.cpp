// URL: https://atcoder.jp/contests/abc055/submissions/4632665
// Date: Tue, 19 Mar 2019 20:34:16 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
  int n;
  cin >> n;
  long long ans = 1;
  for (int i = 0; i < n; i++)
    ans = ans * (i + 1) % MOD;
  cout << ans << endl;

  return 0;
}
