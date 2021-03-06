// URL: https://atcoder.jp/contests/abc194/submissions/20693027
// Date: Sat, 06 Mar 2021 21:05:20 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 A, B;
    cin >> A >> B;
    i64 C = A + B;
    if (15 <= C && 8 <= B) {
        cout << 1 << endl;
    } else if (10 <= C && 3 <= B) {
        cout << 2 << endl;
    } else if (3 <= C) {
        cout << 3 << endl;
    } else {
        cout << 4 << endl;
    }
    return 0;
}
