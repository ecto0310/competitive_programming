// URL: https://atcoder.jp/contests/nikkei2019-qual/submissions/4098182
// Date: Sun, 27 Jan 2019 21:04:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  string A, B, C;
  cin >> N >> A >> B >> C;
  int ans = 0;
  for (int i = 0; i < N; i++)
  {
    map<char, int> m;
    m[A[i]]++;
    m[B[i]]++;
    m[C[i]]++;
    ans += 3 - max({m[A[i]], m[B[i]], m[C[i]]});
  }
  cout << ans << endl;

  return 0;
}
