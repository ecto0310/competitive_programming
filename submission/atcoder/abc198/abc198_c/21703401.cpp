// URL: https://atcoder.jp/contests/abc198/submissions/21703401
// Date: Mon, 12 Apr 2021 06:34:53 +0900
// Language: C++ (GCC 9.2.1)
#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 R, X, Y;
    cin >> R >> X >> Y;
    if (sqrtl(X * X + Y * Y) < R) {
        cout << 2 << endl;
    } else {
        cout << ceil(sqrt(X * X + Y * Y) / R) << endl;
    }
    return 0;
}
