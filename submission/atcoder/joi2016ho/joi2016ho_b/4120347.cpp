// URL: https://atcoder.jp/contests/joi2016ho/submissions/4120347
// Date: Tue, 29 Jan 2019 15:31:49 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  string S;
  cin >> N >> S;
  vector<int> cntJ(N + 1, 0), cntI(N + 1, 0);
  for (int i = 0; i < N; i++)
  {
    cntJ[i + 1] = cntJ[i] + (S[i] == 'J');
    cntI[i + 1] = cntI[i] + (S[i] == 'I');
  }
  long long def = 0;
  for (int i = 0; i < N; i++)
    def += (S[i] == 'O') * cntJ[i + 1] * (cntI[N] - cntI[i]);
  long long ansJ = 0, ansO = 0, ansI = 0;
  for (int i = 0; i < N; i++)
  {
    ansJ += (S[i] == 'O') * (cntI[N] - cntI[i]);
    ansI += (S[i] == 'O') * cntJ[i + 1];
    ansO = max(ansO, (long long)cntJ[i + 1] * (cntI[N] - cntI[i]));
  }
  cout << max({ansJ, ansO, ansI}) + def << endl;

  return 0;
}
