// URL: https://atcoder.jp/contests/caddi2018b/submissions/3851019
// Date: Sat, 22 Dec 2018 23:03:54 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  int cnt = 0;
  for (int i = 0; i < n; i++)
    if (a[i] % 2 == 1)
    {
      cout << "first" << endl;
      return 0;
    }
  cout << "second" << endl;

  return 0;
}
