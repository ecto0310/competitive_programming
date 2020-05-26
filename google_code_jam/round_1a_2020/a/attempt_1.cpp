// URL: (practice)
// Date: Sat, 11 Apr 2020 15:59:00 +0900
// Language: C++14 (G++)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 T;
  cin >> T;
  for (i64 _ = 1; _ <= T; _++)
  {
    i64 N;
    cin >> N;
    vector<string> P(N);
    for (i64 i = 0; i < N; i++)
      cin >> P[i];
    string pref, suf;
    vector<string> sub;
    bool ok = true;
    for (string s : P)
    {
      i64 last = -1;
      for (i64 i = 0; i < s.size(); i++)
      {
        if (s[i] == '*')
        {
          if (last == -1)
          {
            string tpref = s.substr(0, i);
            if (pref.size() < tpref.size())
              swap(pref, tpref);
            if (pref.substr(0, tpref.size()) != tpref)
            {
              ok = false;
              break;
            }
          }
          else
            sub.push_back(s.substr(last + 1, i - last - 1));
          last = i;
        }
      }
      string tsuf = s.substr(last + 1);
      if (suf.size() < tsuf.size())
        swap(suf, tsuf);
      if (suf.substr(suf.size() - tsuf.size()) != tsuf)
      {
        ok = false;
        break;
      }
    }
    cout << "Case #" << _ << ": ";
    if (ok)
    {
      cout << pref;
      for (string i : sub)
        cout << i;
      cout << suf << endl;
    }
    else
      cout << "*" << endl;
  }
  return 0;
}
