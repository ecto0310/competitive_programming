// URL: https://atcoder.jp/contests/abc108/submissions/4632758
// Date: Tue, 19 Mar 2019 20:42:33 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
  int n, k;
  cin >> n >> k;
  map<int, long long> m;
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    m[i % k]++;
  for (int i = 0; i < k; i++)
    if (2 * i % k == 0)
      ans += m[i] * m[i] * m[(k - i) % k];
  cout << ans << endl;

  return 0;
}
