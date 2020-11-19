// URL: https://atcoder.jp/contests/agc022/submissions/4384235
// Date: Mon, 25 Feb 2019 17:36:15 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string S;
  cin >> S;
  if (S == "zyxwvutsrqponmlkjihgfedcba")
    cout << -1 << endl;
  else if (S.size() == 26)
  {
    string tmp = S;
    next_permutation(tmp.begin(), tmp.end());
    for (int i = 0; i < 26; i++)
    {
      cout << tmp[i];
      if (S[i] != tmp[i])
        break;
    }
    cout << endl;
  }
  else
  {
    bool use[26] = {};
    for (int i = 0; i < S.size(); i++)
      use[S[i] - 'a'] = true;
    for (int i = 0; i < 26; i++)
      if (!use[i])
      {
        cout << S << (char)('a' + i) << endl;
        break;
      }
  }

  return 0;
}
