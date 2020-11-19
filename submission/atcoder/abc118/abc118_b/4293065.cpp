// URL: https://atcoder.jp/contests/abc118/submissions/4293065
// Date: Sat, 16 Feb 2019 23:19:01 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  map<int, int> cnt;
  for (int i = 0; i < N; i++)
  {
    int K;
    cin >> K;
    for (int j = 0; j < K; j++)
    {
      int A;
      cin >> A;
      cnt[A]++;
    }
  }
  int ans = 0;
  for (pair<int, int> t : cnt)
    if (t.second == N)
      ans++;
  cout << ans << endl;

  return 0;
}
