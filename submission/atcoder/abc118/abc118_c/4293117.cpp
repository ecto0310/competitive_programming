// URL: https://atcoder.jp/contests/abc118/submissions/4293117
// Date: Sat, 16 Feb 2019 23:20:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  int ans = __gcd(A[0], A[1]);
  for (int i = 2; i < N; i++)
    ans = __gcd(ans, A[i]);
  cout << ans << endl;

  return 0;
}
