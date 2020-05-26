// URL: https://atcoder.jp/contests/abc117/submissions/4161454
// Date: Sun, 03 Feb 2019 21:48:55 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  long long K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i];
  int cnt[40] = {};
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < 40; j++)
      if (A[i] & (1LL << j))
        cnt[j]++;
  }
  long long tmp = 0;
  for (int i = 39; - 1 < i; i--)
  {
    if (cnt[i] < N - cnt[i] && (tmp | (1LL << i)) <= K)
      tmp |= (1LL << i);
  }
  long long ans = 0;
  for (int i = 0; i < N; i++)
    ans += tmp ^ A[i];
  cout << ans << endl;

  return 0;
}
