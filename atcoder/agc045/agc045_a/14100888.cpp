// URL: https://atcoder.jp/contests/agc045/submissions/14100888
// Date: Mon, 08 Jun 2020 00:50:20 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 T;
  cin >> T;
  while (T--)
  {
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for (i64 i = 0; i < N; i++)
      cin >> A[i];
    string S;
    cin >> S;
    vector<i64> b;
    for (i64 i = N; 0 <= i; i--)
    {
      i64 x = A[i];
      for (i64 j : b)
        x = min(x, j ^ x);
      if (x != 0)
      {
        if (S[i] == '1')
        {
          cout << "1" << endl;
          goto fin;
        }
        b.push_back(x);
      }
    }
    cout << "0" << endl;
  fin:;
  }
  return 0;
}
