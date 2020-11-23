// URL: https://atcoder.jp/contests/abc182/submissions/18362284
// Date: Mon, 23 Nov 2020 14:01:02 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  i64 ans = -1, cnt = 0;
  for (i64 i = 2; i <= 1000; i++)
  {
    i64 tmp = 0;
    for (i64 j = 0; j < N; j++)
      if (A[j] % i == 0)
        tmp++;
    if (cnt < tmp)
    {
      cnt = tmp;
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
