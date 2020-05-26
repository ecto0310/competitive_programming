// URL: https://atcoder.jp/contests/aising2019/submissions/3984487
// Date: Sat, 12 Jan 2019 21:04:40 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  int cntA = 0, cntB = 0, cntC = 0;
  for (int i = 0; i < N; i++)
  {
    int P;
    cin >> P;
    if (P <= A)
      cntA++;
    else if (P <= B)
      cntB++;
    else
      cntC++;
  }
  cout << min({cntA, cntB, cntC}) << endl;

  return 0;
}
