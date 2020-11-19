// URL: https://atcoder.jp/contests/arc040/submissions/10485274
// Date: Mon, 02 Mar 2020 15:46:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N;
  cin >> N;
  vector<string> S(N);
  for (i64 i = 0; i < N; i++)
    cin >> S[i];
  i64 ans = 0;
  for (i64 i = 0; i < N; i++)
    for (i64 j = N - 1; 0 <= j; j--)
      if (S[i][j] == '.')
      {
        ans++;
        if (i + 1 < N)
          for (i64 k = j; j < N; j++)
            S[i + 1][j] = 'o';
        break;
      }
  cout << ans << endl;
  return 0;
}
