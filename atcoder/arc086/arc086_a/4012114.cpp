// URL: https://atcoder.jp/contests/arc086/submissions/4012114
// Date: Mon, 14 Jan 2019 11:09:46 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> cnt(N + 1);
  for (int i = 0; i < N; i++)
  {
    int A;
    cin >> A;
    cnt[A]++;
  }
  sort(cnt.begin(), cnt.end(), greater<int>());
  int ans = 0;
  for (int i = K; i < N; i++)
    ans += cnt[i];
  cout << ans << endl;

  return 0;
}
