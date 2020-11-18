// URL: https://atcoder.jp/contests/joi2021yo1b/submissions/18212453
// Date: Thu, 19 Nov 2020 07:43:55 +0900
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
  for (i64 i = 0; i < N; i++)
    for (i64 j = i + 1; j < N; j++)
      for (i64 k = j + 1; k < N; k++)
        if (S[i] == 'I' && S[j] == 'O' && S[k] == 'I')
        {
          cout << "Yes" << endl;
          return 0;
        }
  cout << "No" << endl;
  return 0;
}
