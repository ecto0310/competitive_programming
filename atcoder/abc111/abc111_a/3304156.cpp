// URL: https://atcoder.jp/contests/abc111/submissions/3304156
// Date: Sun, 30 Sep 2018 00:05:52 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  string n;
  cin >> n;
  for (int i = 0; i < 3; i++)
    cout << (n[i] == '1' ? '9' : '1');
  cout << endl;

  return 0;
}
