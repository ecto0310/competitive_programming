// URL: https://atcoder.jp/contests/abc006/submissions/4642629
// Date: Wed, 20 Mar 2019 23:12:17 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  if (n * 2 > m || n * 4 < m)
    cout << "-1 -1 -1" << endl;
  else if (n * 3 > m)
    cout << n * 3 - m << " " << m - n * 2 << " 0" << endl;
  else
    cout << "0 " << n * 4 - m << " " << m - n * 3 << endl;

  return 0;
}
