// URL: https://atcoder.jp/contests/keyence2019/submissions/3998412
// Date: Sun, 13 Jan 2019 21:01:35 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int N[4];
  for (int i = 0; i < 4; i++)
    cin >> N[i];
  sort(N, N + 4);
  if (N[0] == 1 && N[1] == 4 && N[2] == 7 && N[3] == 9)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
