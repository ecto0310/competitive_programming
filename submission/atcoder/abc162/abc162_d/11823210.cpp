// URL: https://atcoder.jp/contests/abc162/submissions/11823210
// Date: Sun, 12 Apr 2020 21:29:56 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  string S;
  cin >> N >> S;
  vector<i64> cntR(N + 1), cntG(N + 1), cntB(N + 1);
  for (i64 i = 0; i < N; i++)
  {
    cntR[i + 1] = cntR[i] + (S[i] == 'R');
    cntG[i + 1] = cntG[i] + (S[i] == 'G');
    cntB[i + 1] = cntB[i] + (S[i] == 'B');
  }
  i64 ans = 0;
  for (i64 i = 1; i < N - 1; i++)
    for (i64 j = 0; j < i; j++)
    {
      if (S[i] == 'R')
      {
        if (S[j] == 'G')
          ans += cntB[N] - cntB[i] - (i + i - j < N && S[i + i - j] == 'B' ? 1 : 0);
        else if (S[j] == 'B')
          ans += cntG[N] - cntG[i] - (i + i - j < N && S[i + i - j] == 'G' ? 1 : 0);
      }
      else if (S[i] == 'G')
      {
        if (S[j] == 'R')
          ans += cntB[N] - cntB[i] - (i + i - j < N && S[i + i - j] == 'B' ? 1 : 0);
        else if (S[j] == 'B')
          ans += cntR[N] - cntR[i] - (i + i - j < N && S[i + i - j] == 'R' ? 1 : 0);
      }
      else
      {
        if (S[j] == 'R')
          ans += cntG[N] - cntG[i] - (i + i - j < N && S[i + i - j] == 'G' ? 1 : 0);
        else if (S[j] == 'G')
          ans += cntR[N] - cntR[i] - (i + i - j < N && S[i + i - j] == 'R' ? 1 : 0);
      }
    }
  cout << ans << endl;
  return 0;
}
