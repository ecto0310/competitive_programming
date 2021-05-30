// URL: https://atcoder.jp/contests/abc203/submissions/23037080
// Date: Sun, 30 May 2021 21:02:28 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 a, b, c;
    cin >> a >> b >> c;
    if (a == b) {
        cout << c << endl;
    } else if (a == c) {
        cout << b << endl;
    } else if (b == c) {
        cout << a << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
