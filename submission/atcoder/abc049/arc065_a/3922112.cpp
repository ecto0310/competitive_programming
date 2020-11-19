// URL: https://atcoder.jp/contests/abc049/submissions/3922112
// Date: Thu, 03 Jan 2019 20:03:03 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

string t[4] = {"maerd", "remaerd", "esare", "resare"};

int main()
{
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  while (s.size())
  {
    bool del = false;
    for (int i = 0; i < 4; i++)
      if (s.substr(0, t[i].size()) == t[i])
      {
        s.erase(s.begin(), s.begin() + t[i].size());
        del = true;
      }
    if(!del)
      break;
  }
  cout << (s.size() == 0 ? "YES" : "NO") << endl;

  return 0;
}
