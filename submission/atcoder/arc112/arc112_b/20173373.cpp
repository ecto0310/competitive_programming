// URL: https://atcoder.jp/contests/arc112/submissions/20173373
// Date: Sun, 14 Feb 2021 13:50:11 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 B, C;
    cin >> B >> C;
    if (B == 0) {
        cout << C / 2 + (C - 1) / 2 + 1 << endl;
    } else if (0 < B) {
        cout << C / 2 + (C - 1) / 2 * 2 + (C - 2) / 2 + 2 - max(0LL, (-B + (C - 1) / 2) - (B - C / 2) + 1) << endl;
    } else {
        cout << C / 2 + (C - 1) / 2 * 2 + (C - 2) / 2 + 2 - max(0LL, (B + (C - 2) / 2) - (-B - (C - 1) / 2) + 1) << endl;
    }
    return 0;
}
