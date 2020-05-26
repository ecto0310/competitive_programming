// URL: https://codingcompetitions.withgoogle.com/977aa0a0-7659-4693-b71e-3c7899291d99
// Date: Sat, 2 May 2020 18:10:37 +0900
// Language: C++14 (G++)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  int T;
  cin >> T;
  for (i64 _ = 1; _ <= T; _++)
  {
    i64 X, Y;
    string S;
    cin >> X >> Y >> S;
    for (i64 i = 0; i < S.size(); i++)
    {
      if (S[i] == 'N')
        Y++;
      else if (S[i] == 'S')
        Y--;
      else if (S[i] == 'W')
        X--;
      else
        X++;
      if (abs(X) + abs(Y) <= i + 1)
      {
        cout << "Case #" << _ << ": " << i + 1 << endl;
        goto fin;
      }
    }
    cout << "Case #" << _ << ": "
         << "IMPOSSIBLE" << endl;
  fin:;
  }
  return 0;
}
