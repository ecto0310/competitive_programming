// URL: https://atcoder.jp/contests/abc199/submissions/22017263
// Date: Sat, 24 Apr 2021 21:37:34 +0900
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    i64 N, Q;
    string S;
    cin >> N >> S >> Q;
    bool reverse = false;
    for (i64 _ = 0; _ < Q; _++) {
        i64 T, A, B;
        cin >> T >> A >> B;
        if (T == 1) {
            if (reverse) {
                swap(S[(N < A ? A - 1 - N : A - 1 + N)], S[(N < B ? B - 1 - N : B - 1 + N)]);
            } else {
                swap(S[A - 1], S[B - 1]);
            }
        } else {
            reverse = !reverse;
        }
    }
    if (reverse) {
        cout << S.substr(N, N) << S.substr(0, N) << endl;
    } else {
        cout << S << endl;
    }
    return 0;
}
