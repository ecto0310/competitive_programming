// URL: https://atcoder.jp/contests/agc031/submissions/4596299
// Date: Sat, 16 Mar 2019 21:05:42 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
  int N;
  string S;
  cin >> N >> S;
  int cnt[26] = {};
  for (int i = 0; i < N; i++)
    cnt[S[i] - 'a']++;
  long long ans = cnt[0] + 1;
  for (int i = 1; i < 26; i++)
    ans = ans * (cnt[i] + 1) % MOD;
  cout << (ans + MOD - 1) % MOD << endl;

  return 0;
}
