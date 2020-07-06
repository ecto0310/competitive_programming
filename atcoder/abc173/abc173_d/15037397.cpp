// URL: https://atcoder.jp/contests/abc173/submissions/15037397
// Date: Mon, 06 Jul 2020 13:24:12 +0900
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
  sort(A.rbegin(), A.rend());
  i64 ans = A[0];
  i64 j = 1, cnt = 0;
  for (i64 i = 2; i < N; i++)
  {
    cnt++;
    ans += A[j];
    if (cnt == 2)
    {
      cnt = 0;
      j++;
    }
  }
  cout << ans << endl;
  return 0;
}
