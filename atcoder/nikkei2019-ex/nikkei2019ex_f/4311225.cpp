// URL: https://atcoder.jp/contests/nikkei2019-ex/submissions/4311225
// Date: Mon, 18 Feb 2019 16:22:38 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++)
  {
    bool ok = false;
    if (i % 2 == 0)
    {
      cout << "a";
      ok = true;
    }
    if (i % 3 == 0)
    {
      cout << "b";
      ok = true;
    }
    if (i % 4 == 0)
    {
      cout << "c";
      ok = true;
    }
    if (i % 5 == 0)
    {
      cout << "d";
      ok = true;
    }
    if (i % 6 == 0)
    {
      cout << "e";
      ok = true;
    }
    if (!ok)
      cout << i;
    cout << endl;
  }

  return 0;
}
