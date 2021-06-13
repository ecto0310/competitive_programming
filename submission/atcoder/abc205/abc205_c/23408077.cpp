// URL: https://atcoder.jp/contests/abc205/submissions/23408077
// Date: Sun, 13 Jun 2021 21:06:09 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 A, B, C;
    cin >> A >> B >> C;
    if (C % 2 == 0) {
        A = abs(A);
        B = abs(B);
    }
    if (A == B) {
        cout << "=" << endl;
    } else if (A < B) {
        cout << "<" << endl;
    } else if (A > B) {
        cout << ">" << endl;
    }
    return 0;
}
