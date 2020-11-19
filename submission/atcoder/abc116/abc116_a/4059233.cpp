// URL: https://atcoder.jp/contests/abc116/submissions/4059233
// Date: Sun, 20 Jan 2019 23:28:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int A, B, C;
  cin >> A >> B >> C;
  if (A * A + B * B == C * C)
    cout << A * B / 2 << endl;
  else if (A * A + C * C == B * B)
    cout << A * C / 2 << endl;
  else
    cout << B * C / 2 << endl;

  return 0;
}
