// URL: https://atcoder.jp/contests/abc035/submissions/4248000
// Date: Wed, 13 Feb 2019 02:08:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, Q;
  cin >> N >> Q;
  vector<int> ans(N, 0);
  for (int i = 0; i < Q; i++)
  {
    int l, r;
    cin >> l >> r;
    ans[l - 1]++;
    if (r != N)
      ans[r]--;
  }
  for (int i = 0; i < N - 1; i++)
    ans[i + 1] += ans[i];
  for (int i = 0; i < N; i++)
    cout << ans[i] % 2;
  cout << endl;

  return 0;
}
