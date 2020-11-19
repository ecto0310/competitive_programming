// URL: https://atcoder.jp/contests/arc062/submissions/4021826
// Date: Wed, 16 Jan 2019 02:12:05 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] == 'p')
      cnt++;
  cout << s.size() / 2 - cnt << endl;

  return 0;
}
