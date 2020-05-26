// URL: https://atcoder.jp/contests/abc121/submissions/4526713
// Date: Sat, 09 Mar 2019 22:16:36 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  long long A, B;
  cin >> A >> B;
  long long ans = 0, now = 1;
  B++;
  for (int i = 0; i < 63; i++)
  {
    long long cntA, cntB;
    cntA = A / (now * 2) * now + ((A + now - 1) / now % 2 == 0 ? A % now : 0);
    cntB = B / (now * 2) * now + ((B + now - 1) / now % 2 == 0 ? B % now : 0);
    if ((cntB - cntA) % 2 == 1)
      ans |= (1LL << i);
    now *= 2;
  }
  cout << ans << endl;

  return 0;
}
