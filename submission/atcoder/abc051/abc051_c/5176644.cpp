// URL: https://atcoder.jp/contests/abc051/submissions/5176644
// Date: Sun, 28 Apr 2019 21:08:41 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

int main()
{
    i64 sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    i64 dx = tx - sx, dy = ty - sy;
    cout << string(dy, 'U') << string(dx, 'R');
    cout << string(dy, 'D') << string(dx, 'L');
    cout << "L" << string(dy + 1, 'U') << string(dx + 1, 'R') << "D";
    cout << "R" << string(dy + 1, 'D') << string(dx + 1, 'L') << "U";
    cout << endl;
    return 0;
}
