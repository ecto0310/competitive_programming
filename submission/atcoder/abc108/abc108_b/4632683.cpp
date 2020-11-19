// URL: https://atcoder.jp/contests/abc108/submissions/4632683
// Date: Tue, 19 Mar 2019 20:35:21 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
  int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << x2 + y1 - y2 << " " << y2 + x2 - x1 << " " << x1 + y1 - y2 << " " << y1 + x2 - x1 << endl;

  return 0;
}
