// URL: https://atcoder.jp/contests/keyence2019/submissions/3999597
// Date: Sun, 13 Jan 2019 21:04:40 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  for (int i = 0; i < S.size(); i++)
    for (int j = 0; j < S.size() - i; j++)
      if (S.substr(0, i) + S.substr(i + j, S.size() - i - j) == "keyence")
      {
        cout << "YES" << endl;
        return 0;
      }
  cout << "NO" << endl;

  return 0;
}
