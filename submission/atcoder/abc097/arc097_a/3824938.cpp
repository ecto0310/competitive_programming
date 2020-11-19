// URL: https://atcoder.jp/contests/abc097/submissions/3824938
// Date: Thu, 20 Dec 2018 01:17:09 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string s;
  int k;
  cin >> s >> k;
  int size = s.size();
  vector<string> p;
  set<string> se;
  for (int i = 0; i < size; i++)
    for (int j = 1; j < size - i + 1 && j < 6; j++)
      if (se.count(s.substr(i, j)) == 0)
      {
        p.push_back(s.substr(i, j));
        se.insert(s.substr(i, j));
      }
  sort(p.begin(), p.end());
  cout << p[k - 1] << endl;

  return 0;
}
