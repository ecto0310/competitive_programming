#include <bits/stdc++.h>

using namespace std;

class PolyominoCovering
{
  int getNext(int now, int N)
  {
    if ((now / N) % 2 == 0)
      return ((now + 1) % N == 0 ? now + N : now + 1);
    else
      return (now % N == 0 ? now + N : now - 1);
  }

public:
  vector<int> findSolution(int N, vector<int> grid, vector<int> tiles)
  {
    vector<int> out(N * N, -1);

    int tileID = 1;
    int now = 0;
    while (now < N * N)
    {
      if (out[now] != -1)
      {
        now = getNext(now, N);
        continue;
      }
      int t = now;
      int bestlen = -1, bestproduct = -1000;
      int product = grid[t];
      for (int l = 2; l <= 7; l++)
      {
        t = getNext(t, N);
        if (N * N <= t)
        {
          int cnt = 0;
          for (int i = 0; i < 6; i++)
            cnt += tiles[i];
          if (2 < l && -1000 * (l - 1) < product & 0 < tiles[l - 3])
            bestlen = l - 1;
          break;
        }
        product *= grid[t];
        if (0 < tiles[l - 2] && bestproduct < product)
        {
          bestlen = l;
          bestproduct = product;
        }
      }
      if (bestlen != -1)
      {
        t = now;
        for (int i = 0; i < bestlen; i++)
        {
          out[t] = tileID;
          t = getNext(t, N);
        }
        tileID++;
        tiles[bestlen - 2]--;
      }
      now = getNext(now, N);
    }

    return out;
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
  PolyominoCovering pc;
  int N;
  cin >> N;
  vector<int> grid(N * N);
  getVector(grid);
  vector<int> tiles(6);
  getVector(tiles);

  vector<int> ret = pc.findSolution(N, grid, tiles);
  cout << ret.size() << endl;
  for (int i = 0; i < (int)ret.size(); ++i)
    cout << ret[i] << endl;
  cout.flush();
}
