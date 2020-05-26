// URL: https://atcoder.jp/contests/abc158/submissions/10603701
// Date: Sat, 07 Mar 2020 21:16:13 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  string S;
  i64 Q;
  cin >> S >> Q;
  list<char> ans;
  for (char i : S)
    ans.push_back(i);
  bool t = true;
  for (i64 _ = 0; _ < Q; _++)
  {
    i64 T;
    cin >> T;
    if (T == 1)
      t = !t;
    else
    {
      i64 F;
      char C;
      cin >> F >> C;
      if (t)
      {
        if (F == 1)
          ans.push_front(C);
        else
          ans.push_back(C);
      }
      else
      {
        if (F == 1)
          ans.push_back(C);
        else
          ans.push_front(C);
      }
    }
  }
  if (!t)
    reverse(ans.begin(), ans.end());
  for (char i : ans)
    cout << i;
  cout << endl;
  return 0;
}
