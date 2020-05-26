// URL: https://atcoder.jp/contests/mujin-pc-2018/submissions/4021756
// Date: Wed, 16 Jan 2019 01:50:32 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int A;
  string S;
  cin >> A >> S;
  bool ok = (A == 0 ? true : false);
  for (int i = 0; i < S.size(); i++)
  {
    A += (S[i] == '+' ? 1 : -1);
    if (A == 0)
      ok = true;
  }
  cout << (ok ? "Yes" : "No") << endl;

  return 0;
}
