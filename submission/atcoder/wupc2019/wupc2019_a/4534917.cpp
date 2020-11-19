// URL: https://atcoder.jp/contests/wupc2019/submissions/4534917
// Date: Sun, 10 Mar 2019 13:06:04 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string s;
  cin >> s;
  int size = s.size();
  for (int i = 0; i < size - 1; i++)
    if (s.substr(i, 2) == "WA")
    {
      s[i] = 'A';
      s[i + 1] = 'C';
      if (-1 <= i - 2)
        i -= 2;
    }
  cout << s << endl;

  return 0;
}
