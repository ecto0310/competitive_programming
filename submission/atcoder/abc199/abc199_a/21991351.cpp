// URL: https://atcoder.jp/contests/abc199/submissions/21991351
// Date: Sat, 24 Apr 2021 21:00:51 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 A, B, C;
    cin >> A >> B >> C;
    if (A * A + B * B < C * C) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
