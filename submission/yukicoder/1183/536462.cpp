// URL: https://yukicoder.me/submissions/536462
// Date: Sat, 22 Aug 2020 13:06:33 +0900
// Language: C++17(1z)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 N;
  cin >> N;
  vector<i64> A(N), B(N);
  for (i64 i = 0; i < N; i++)
    cin >> A[i];
  for (i64 i = 0; i < N; i++)
    cin >> B[i];
  i64 ans = 0;
  bool diff = false;
  for (i64 i = 0; i < N; i++)
    if (A[i] == B[i])
    {
      if (diff)
        ans++;
      diff = false;
    }
    else
    {
      diff = true;
    }
  if (diff)
    ans++;
  cout << ans << endl;
  return 0;
}
