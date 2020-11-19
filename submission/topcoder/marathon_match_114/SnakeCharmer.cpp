#include <bits/stdc++.h>

using namespace std;

const long long cyclePerSec = 2800000000;

long long getCycle()
{
  unsigned int low, high;
  __asm__ volatile("rdtsc"
                   : "=a"(low), "=d"(high));
  return ((long long)low) | ((long long)high << 32);
}

inline int pow(int base, int ind)
{
  int ret = 1;
  for (int i = 0; i < ind; i++)
    ret *= base;
  return ret;
}

random_device seed_gen;
mt19937 engine(seed_gen());

const int dX[4] = {0, -1, 0, 1};
const int dY[4] = {-1, 0, 1, 0};

pair<int, int> bfsQueue[2500];

struct Data
{
  string answer;
  int n;
  int grid[51][51];
  int posX, posY;
  int length;
  int score = 0, movable = 1e9;

  void setMovable()
  {
    movable = 0;
    bool stay[51][51] = {};
    int queueSize = 1;
    bfsQueue[0] = {posX, posY};
    for (int i = 0; i < queueSize; i++)
    {
      for (int j = 0; j < 4; j++)
      {
        int moveX = bfsQueue[i].first + dX[j], moveY = bfsQueue[i].second + dY[j];
        if (grid[moveX][moveY] == -1 && !stay[moveX][moveY])
        {
          movable++;
          stay[moveX][moveY] = true;
          bfsQueue[queueSize++] = {moveX, moveY};
        }
      }
    }
    return;
  }

  void setScore(string snake)
  {
    score = 0;
    int size = answer.size();
    for (int i = 0; i < size; i++)
    {
      if (answer[i] == 'L')
        posY--;
      if (answer[i] == 'R')
        posY++;
      if (answer[i] == 'U')
        posX++;
      if (answer[i] == 'D')
        posX--;
      grid[posX][posY] = snake[length - i - 1] - '0';
    }
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        int match = 1;
        for (int k = 0; k < 4; k++)
        {
          int moveX = i + dX[k], moveY = j + dY[k];
          if (grid[i][j] == grid[moveX][moveY])
          {
            match++;
          }
        }

        score += pow(grid[i][j], match);
      }
    }
    return;
  }

  vector<char> output()
  {
    int size = answer.size();
    vector<char> ret(size);
    for (int i = 0; i < size; i++)
      ret[i] = answer[i];
    return ret;
  }

  Data() {}
  Data(int n, int start, int length)
  {
    this->n = n;
    posX = n / 2 + 1;
    posY = n / 2 + 1;
    this->length = length;
    for (int i = 0; i <= n + 1; i++)
    {
      grid[i][0] = -2;
      grid[i][n + 1] = -2;
      grid[0][i] = -2;
      grid[n + 1][i] = -2;
    }
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        grid[i][j] = -1;
      }
    }
    grid[posX][posY] = start;
    score = start;
  }

  bool operator<(const Data &r) const
  {
    return score < r.score;
  };
};

class SnakeCharmer
{
private:
  const char character[4] = {'L', 'D', 'R', 'U'};
  const int beamWide = 25;

public:
  vector<char> findSolution(int n, int v, string snake)
  {
    long long baseTime = getCycle();

    int size = n * n - 1;
    Data answer(n, snake[size] - '0', size);
    answer.answer.resize(size);
    for (int i = 0, dir = 0, L = 1; i < size;)
    {
      for (int k = 0; k < L && i < size; k++, i++)
        answer.answer[i] += character[dir];
      dir = (dir + 1) % 4;
      for (int k = 0; k < L && i < size; k++, i++)
        answer.answer[i] = character[dir];
      dir = (dir + 1) % 4;
      L++;
    }
    answer.setScore(snake);
    bool check[2401] = {};
    bool last = true;
    for (int length = size * 7 / 10; length <= size && (double)(getCycle() - baseTime) / cyclePerSec < 9.5; length += (last ? min(size - length, (int)sqrt(size)) : -(int)sqrt(sqrt(size))))
    {
      while (check[length] && 0 < length)
        length--;
      while (length < 0 || (check[length] && length <= size))
        length++;
      if (check[length])
        break;
      check[length] = true;
      vector<Data> current(beamWide), next(beamWide);
      int currentSize = 1, nextSize;
      current[0] = Data(n, snake[length] - '0', length);
      for (int turn = 0; turn < length && (double)(getCycle() - baseTime) / cyclePerSec < 9.5; turn++)
      {
        if (currentSize == 0)
          break;
        nextSize = 0;
        for (int now = 0; now < currentSize; now++)
        {
          for (int i = 0; i < 4; i++)
          {
            int moveX = current[now].posX + dX[i], moveY = current[now].posY + dY[i];
            if (current[now].grid[moveX][moveY] == -1)
            {
              int number = snake[length - turn - 1] - '0';
              Data tmp = current[now];
              tmp.posX = moveX;
              tmp.posY = moveY;
              tmp.answer += character[i];
              tmp.length--;
              for (int j = 0; j < 4; j++)
              {
                int move2X = moveX + dX[j], move2Y = moveY + dY[j];
                if (tmp.grid[move2X][move2Y] == number)
                {
                  int match = 1;
                  for (int k = 0; k < 4; k++)
                  {
                    int move3X = move2X + dX[k], move3Y = move2Y + dY[k];
                    if (tmp.grid[move3X][move3Y] == tmp.grid[move2X][move2Y])
                    {
                      match++;
                    }
                  }
                  tmp.score -= pow(number, match);
                }
              }
              tmp.grid[moveX][moveY] = number;
              for (int j = 0; j < 4; j++)
              {
                int move2X = moveX + dX[j], move2Y = moveY + dY[j];
                if (tmp.grid[move2X][move2Y] == number)
                {
                  int match = 1;
                  for (int k = 0; k < 4; k++)
                  {
                    int move3X = move2X + dX[k], move3Y = move2Y + dY[k];
                    if (tmp.grid[move3X][move3Y] == tmp.grid[move2X][move2Y])
                    {
                      match++;
                    }
                  }
                  tmp.score += pow(number, match);
                }
              }
              int match = 1;
              for (int j = 0; j < 4; j++)
              {
                int move2X = moveX + dX[j], move2Y = moveY + dY[j];
                if (tmp.grid[move2X][move2Y] == tmp.grid[moveX][moveY])
                {
                  match++;
                }
              }
              tmp.score += pow(number, match);
              tmp.setMovable();
              if (tmp.length <= tmp.movable)
              {
                nextSize = min(nextSize + 1, beamWide);
                for (int j = 0; j < nextSize; j++)
                {
                  if (next[j] < tmp)
                  {
                    swap(tmp, next[j]);
                  }
                }
              }
            }
          }
        }
        current = next;
        currentSize = nextSize;
      }
      last = (0 < currentSize);
      if (0 < currentSize && current[0].answer.size() == length && answer.score < current[0].score)
        answer = current[0];
    }
    return answer.output();
  }
};

int main()
{
  SnakeCharmer prog;
  int n;
  int v;
  string snake;
  cin >> n;
  cin >> v;
  cin >> snake;

  vector<char> ret = prog.findSolution(n, v, snake);
  cout << ret.size() << endl;
  for (int i = 0; i < (int)ret.size(); ++i)
  {
    cout << ret[i] << endl;
  }
  cout.flush();
  return 0;
}
