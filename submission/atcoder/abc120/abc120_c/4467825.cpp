// URL: https://atcoder.jp/contests/abc120/submissions/4467825
// Date: Mon, 04 Mar 2019 18:08:48 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  int cnt = 0;
  for (char t : S)
    if (t == '0')
      cnt++;
  cout << min(cnt, (int)S.size() - cnt) * 2 << endl;

  return 0;
}
