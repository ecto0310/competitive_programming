// URL: https://atcoder.jp/contests/past201912-open/submissions/10798213
// Date: Fri, 13 Mar 2020 19:38:26 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  string S;
  cin >> S;
  vector<string> w;
  bool b = false;
  for (char i : S)
    if ('A' <= i && i <= 'Z')
    {
      if (b)
      {
        w[w.size() - 1] += string(1, i);
        b = false;
      }
      else
      {
        w.push_back(string(1, i));
        b = true;
      }
    }
    else
      w[w.size() - 1] += string(1, i + 'A' - 'a');
  sort(w.begin(), w.end());
  for (string i : w)
  {
    transform(i.begin() + 1, i.end() - 1, i.begin() + 1, ::tolower);
    cout << i;
  }
  cout << endl;
  return 0;
}
