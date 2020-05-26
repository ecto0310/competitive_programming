// URL: https://atcoder.jp/contests/arc006/submissions/12949771
// Date: Fri, 08 May 2020 17:31:50 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 E[6], B, L[6];
  for (i64 i = 0; i < 6; i++)
    cin >> E[i];
  cin >> B;
  for (i64 i = 0; i < 6; i++)
    cin >> L[i];
  bool bon = false;
  i64 cnt = 0;
  for (i64 i = 0; i < 6; i++)
  {
    if (L[i] == B)
      bon = true;
    for (i64 j = 0; j < 6; j++)
      if (L[i] == E[j])
        cnt++;
  }
  if (cnt == 6)
    cout << 1 << endl;
  else if (cnt == 5 && bon)
    cout << 2 << endl;
  else if (8 - cnt <= 5)
    cout << 8 - cnt << endl;
  else
    cout << 0 << endl;
  return 0;
}
