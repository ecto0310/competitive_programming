#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
using i64 = long long;

const i64 CYCLE_PER_SEC = 2500000000;

i64 getCycle()
{
    unsigned int low, high;
    __asm__ volatile("rdtsc"
                     : "=a"(low), "=d"(high));
    return ((i64)low) | ((i64)high << 32);
}

class LineUp
{
    i64 n, x;
    vector<int> bef;
    i64 start;

    i64 get_score(vector<int> &arrangements, vector<int> &ans, vector<int> &heights)
    {
        i64 sqErr = 0, move = 0;
        vector<i64> lp(n);
        for (i64 i = 0; i < n; i++)
            lp[i] = i;
        for (i64 i = 0; i < x; i++)
            for (i64 j = 0; j < n; j++)
            {
                i64 err = arrangements[i * n + j] - heights[ans[i * n + j]];
                sqErr += err * err;
                move += abs(j - lp[ans[i * n + j]]);
                lp[ans[i * n + j]] = j;
            }
        return move + sqrt(sqErr);
    }

public:
    vector<int> getLineup(vector<int> heights, vector<int> arrangements)
    {
        start = getCycle();
        n = heights.size();
        x = arrangements.size() / n;
        vector<int> ret(n * x);
        for (i64 i = 0; i < n * x; i++)
            ret[i] = i % n;
        i64 best = 1e9;
        while ((double)(getCycle() - start) / CYCLE_PER_SEC < 9.5)
        {
            i64 t = rand() % x, l = rand() % n, r = rand() % n;
            swap(ret[t * n + l], ret[t * n + r]);
            i64 score = get_score(arrangements, ret, heights);
            if (score < best)
                best = score;
            else
                swap(ret[t * n + l], ret[t * n + r]);
        }
        return ret;
    }
};
// -------8<------- end of solution submitted to the website -------8<-------

template <class T>
void getVector(vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
}

int main()
{
    LineUp sol;
    int size;
    cin >> size;
    vector<int> heights(size);
    getVector(heights);
    cin >> size;
    vector<int> arrangements(size);
    getVector(arrangements);
    vector<int> ret = sol.getLineup(heights, arrangements);
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << endl;
    cout.flush();
}
