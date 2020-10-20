// URL: https://atcoder.jp/contests/joi2021yo1a/submissions/17539619
// Date: Tue, 20 Oct 2020 16:27:36 +0900
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
  i64 cntJ = 0, cntO = 0, cntI = 0;
  for (char i : S)
    if (i == 'J')
      cntJ++;
    else if (i == 'O')
      cntO++;
    else
      cntI++;
  cout << string(cntJ, 'J') + string(cntO, 'O') + string(cntI, 'I') << endl;
  return 0;
}
