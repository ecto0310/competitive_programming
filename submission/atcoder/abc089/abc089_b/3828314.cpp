// URL: https://atcoder.jp/contests/abc089/submissions/3828314
// Date: Thu, 20 Dec 2018 21:19:20 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  set<string> se;
  for (int i = 0; i < n; i++)
  {
    string s;
    cin >> s;
    se.insert(s);
  }
  cout << (se.size() == 3 ? "Three" : "Four") << endl;

  return 0;
}
