// URL: https://atcoder.jp/contests/abc198/submissions/21703398
// Date: Mon, 12 Apr 2021 06:34:19 +0900
// Language: C++ (GCC 9.2.1)
#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main() {
    string S[3];
    cin >> S[0] >> S[1] >> S[2];
    map<char, i64> m;
    for (i64 i = 0; i < 3; i++) {
        for (char j:S[i]) {
            m[j] = -1;
        }
    }
    if (11 <= m.size()) {
        cout << "UNSOLVABLE" << endl;
        return 0;
    }
    vector<i64> num = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    do {
        i64 c = 0;
        for (pair<char, i64> i: m) {
            m[i.first] = num[c];
            c++;
        }
        i64 N[3] = {};
        bool ok = true;
        for (i64 i = 0; i < 3; i++) {
            if (m[S[i][0]] == 0) {
                ok = false;
            }
            for (char j:S[i]) {
                N[i] *= 10;
                N[i] += m[j];
            }
            if (N[i] == 0) {
                ok = false;
            }
        }
        if (ok && N[0] + N[1] == N[2]) {
            cout << N[0] << endl << N[1] << endl << N[2] << endl;
            return 0;
        }
    } while (next_permutation(num.begin(), num.end()));
    cout << "UNSOLVABLE" << endl;
    return 0;
}
