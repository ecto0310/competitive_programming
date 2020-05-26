// URL: https://atcoder.jp/contests/agc026/submissions/4121908
// Date: Tue, 29 Jan 2019 20:23:34 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  string S;
  cin >> N >> S;
  map<string, long long> m;
  for (int bit = 0; bit < (1 << N); bit++)
  {
    string r, b;
    for (int i = 0; i < N; i++)
      if (bit & (1 << i))
        r += S[i];
      else
        b += S[i];
    m[r + "-" + b]++;
  }
  long long ans = 0;
  for (int bit = 0; bit < (1 << N); bit++)
  {
    string r, b;
    for (int i = 0; i < N; i++)
      if (bit & (1 << i))
        r += S[N + i];
      else
        b += S[N + i];
    reverse(r.begin(), r.end());
    reverse(b.begin(), b.end());
    ans += m[b + "-" + r];
  }
  cout << ans << endl;

  return 0;
}
