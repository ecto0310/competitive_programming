#include <bits/stdc++.h>
using namespace std;

const double timeLimit = 9.0;
const long long cyclePerSec = 2800000000;
long long baseTime;

unsigned long long int getCycle()
{
  unsigned int low, high;
  __asm__ volatile("rdtsc"
                   : "=a"(low), "=d"(high));
  return ((unsigned long long int)low) | ((unsigned long long int)high << 32);
}

struct Move
{
  int r, c, s;
  char dir;
};

struct Position
{
  int r, c;
};

struct Grid
{
  vector<vector<int>> g, g_;
  vector<Position> pos, pos_;
  void init()
  {
    g = g_;
    pos = pos_;
  }
};

int N, P;
Grid grid;
vector<Move> bestanswer, answer;

void route(Move m)
{
  vector<vector<int>> tmp(m.s, vector<int>(m.s));
  for (int i = 0; i < m.s; i++)
    for (int j = 0; j < m.s; j++)
      tmp[i][j] = grid.g[m.r + i][m.c + j];
  for (int i = 0; i < m.s; i++)
    for (int j = 0; j < m.s; j++)
    {
      int ind[2];
      if (m.dir == 'L')
      {
        ind[0] = j;
        ind[1] = m.s - i - 1;
      }
      else
      {
        ind[0] = m.s - j - 1;
        ind[1] = i;
      }
      grid.g[m.r + i][m.c + j] = tmp[ind[0]][ind[1]];
      grid.pos[tmp[ind[0]][ind[1]]] = {m.r + i, m.c + j};
    }
  return;
}

int moveR(int i, int j, int num)
{
  int ret = 0;
  //Move up
  while (i < grid.pos[num].r)
  {
    Move m = {grid.pos[num].r - 1, grid.pos[num].c, 2, 'R'};
    if (grid.pos[num].c + 1 == N)
    {
      m = {grid.pos[num].r - 1, grid.pos[num].c - 1, 2, 'L'};
    }
    route(m);
    answer.push_back(m);
    ret++;
  }
  //Move down
  while (grid.pos[num].r < i)
  {
    Move m = {grid.pos[num].r, grid.pos[num].c, 2, 'L'};
    if (grid.pos[num].c + 1 == N)
    {
      m = {grid.pos[num].r, grid.pos[num].c - 1, 2, 'R'};
    }
    route(m);
    answer.push_back(m);
    ret++;
  }
  return ret;
}

int moveC(int i, int j, int num)
{
  int ret = 0;
  // Move left
  while (j < grid.pos[num].c)
  {
    Move m = {grid.pos[num].r, grid.pos[num].c - 1, 2, 'L'};
    if (grid.pos[num].r + 1 == N)
    {
      m = {grid.pos[num].r - 1, grid.pos[num].c - 1, 2, 'R'};
    }
    route(m);
    answer.push_back(m);
    ret++;
  }
  // Move right
  while (grid.pos[num].c < j)
  {
    Move m = {grid.pos[num].r, grid.pos[num].c, 2, 'R'};
    if (grid.pos[num].r + 1 == N)
    {
      m = {grid.pos[num].r - 1, grid.pos[num].c, 2, 'L'};
    }
    route(m);
    answer.push_back(m);
    ret++;
  }
  return ret;
}

int moveCR(int i, int j, int num)
{
  int ret = 0;
  ret += moveC(i, j, num);
  ret += moveR(i, j, num);
  return ret;
}

int moveRC(int i, int j, int num)
{
  int ret = 0;
  ret += moveR(i, j, num);
  ret += moveC(i, j, num);
  return ret;
}

int fitRight(int num, int i)
{
  int ret = 0;
  if (grid.pos[num].r != i || grid.pos[num].c != N - 1)
  {
    ret += moveCR(i, N - 1, num - 1);
    if (grid.pos[num].r == i && grid.pos[num].c == N - 2)
    {
      route({i, N - 2, 2, 'L'});
      answer.push_back({i, N - 2, 2, 'L'});
      route({i + 1, N - 2, 2, 'L'});
      answer.push_back({i + 1, N - 2, 2, 'L'});
      route({i, N - 2, 2, 'R'});
      answer.push_back({i, N - 2, 2, 'R'});
      route({i + 1, N - 2, 2, 'R'});
      answer.push_back({i + 1, N - 2, 2, 'R'});
      route({i + 1, N - 2, 2, 'R'});
      answer.push_back({i + 1, N - 2, 2, 'R'});
      ret += 5;
    }
    else
    {
      ret += moveCR(i + 1, N - 1, num);
    }
    route({i, N - 2, 2, 'L'});
    answer.push_back({i, N - 2, 2, 'L'});
    ret += 1;
  }
  return ret;
}

int fitBottom(int num, int i)
{
  int ret = 0;
  if (grid.pos[num].r != N - 1 || grid.pos[num].c != i)
  {
    ret += moveRC(N - 1, i, num - N);
    if (grid.pos[num].r == N - 2 && grid.pos[num].c == i)
    {
      route({N - 2, i, 2, 'R'});
      answer.push_back({N - 2, i, 2, 'R'});
      route({N - 2, i + 1, 2, 'R'});
      answer.push_back({N - 2, i + 1, 2, 'R'});
      route({N - 2, i, 2, 'L'});
      answer.push_back({N - 2, i, 2, 'L'});
      route({N - 2, i + 1, 2, 'L'});
      answer.push_back({N - 2, i + 1, 2, 'L'});
      route({N - 2, i + 1, 2, 'L'});
      answer.push_back({N - 2, i + 1, 2, 'L'});
      ret += 5;
    }
    else
    {
      ret += moveRC(N - 1, i + 1, num);
    }
    route({N - 2, i, 2, 'R'});
    answer.push_back({N - 2, i, 2, 'R'});
    ret += 1;
  }
  return ret;
}

int simulation(long long turn)
{
  grid.init();
  int score = 0;
  for (int i = 0; i < N - 2; i++)
  {
    int num = i * N + i;
    if (turn & (1LL << i) && abs(grid.pos[num].r - (N - 1)) + abs(grid.pos[num].c - (N - 1)) < abs(grid.pos[num].r - i) + abs(grid.pos[num].c - i))
    {
      //far side
      score += moveCR(N - 1, N - 1, num);
    }
    else
    {
      //near side
      score += moveCR(i, i, num);
    }
    vector<int> type(N);
    for (int j = i + 1; j < N; j++)
    {
      num = i * N + j;
      if (turn & (1LL << i) && abs(grid.pos[num].r - (N - 1)) + abs(grid.pos[num].c - (N - j + i)) < abs(grid.pos[num].r - i) + abs(grid.pos[num].c - j) && abs(grid.pos[num].r - (N - 1)) + abs(grid.pos[num].c - (N - j + i)) < abs(grid.pos[num].r - (j)) + abs(grid.pos[num].c - (N - 1)))
      {
        //far right side
        score += moveCR(N - 1, N - j + i, num);
        type[j] = 1;
      }
      else if (turn & (1LL << i) && abs(grid.pos[num].r - (j)) + abs(grid.pos[num].c - (N - 1)) < abs(grid.pos[num].r - i) + abs(grid.pos[num].c - j))
      {
        //far bottom side
        score += moveRC(j, N - 1, num);
        type[j] = 0;
      }
      else
      {
        //near side
        if (j == N - 1 && grid.pos[num - 1].r == i)
        {
          score += fitRight(num, i);
        }
        else
        {
          score += moveCR(i, j, num);
        }
        type[j] = 0;
      }
      num = j * N + i;
      if (turn & (1LL << i) && abs(grid.pos[num].r - (N - j + i)) + abs(grid.pos[num].c - (N - 1)) < abs(grid.pos[num].r - j) + abs(grid.pos[num].c - i))
      {
        //far side
        score += moveRC(N - j + i, N - 1, num);
      }
      else
      {
        //near side
        if (j == N - 1 && grid.pos[num - N].c == i)
        {
          score += fitBottom(num, i);
        }
        else
        {
          score += moveRC(j, i, num);
        }
      }
    }
    if (turn & (1LL << i))
    {
      for (int t = 0; t < 2; t++)
      {
        Move m = {i + 1, i + 1, N - i - 1, 'L'};
        route(m);
        answer.push_back(m);
        score += floor(pow(N - i - 2, 1.5));
        num = i * N + i;
        if (t == 1)
          score += moveCR(i, i, num);
        for (int j = i + 1; j < N; j++)
        {
          num = i * N + j;
          if (j == N - 1 && type[j] <= t)
          {
            score += fitRight(num, i);
          }
          else if (type[j] <= t)
          {
            score += moveCR(i, j, num);
          }
          num = j * N + i;
          if (t == 1)
          {
            if (j == N - 1)
            {
              score += fitBottom(num, i);
            }
            else
            {
              score += moveRC(j, i, num);
            }
          }
        }
      }
    }
  }
  vector<int> cost{0, 1, 2, 1};
  for (int i = 0; i < 4; i++)
  {
    for (int j = N - 2; j < N; j++)
      for (int k = N - 2; k < N; k++)
      {
        cost[i] += (abs(grid.pos[j * N + k].r - j) + abs(grid.pos[j * N + k].c - k)) * P;
      }
    route({N - 2, N - 2, 2, 'L'});
  }
  int ind = min_element(cost.begin(), cost.end()) - cost.begin();
  if (ind == 1)
  {
    route({N - 2, N - 2, 2, 'L'});
    answer.push_back({N - 2, N - 2, 2, 'L'});
    score += 1;
  }
  else if (ind == 2)
  {
    route({N - 2, N - 2, 2, 'L'});
    answer.push_back({N - 2, N - 2, 2, 'L'});
    route({N - 2, N - 2, 2, 'L'});
    answer.push_back({N - 2, N - 2, 2, 'L'});
    score += 2;
  }
  else if (ind == 3)
  {
    route({N - 2, N - 2, 2, 'R'});
    answer.push_back({N - 2, N - 2, 2, 'R'});
    score += 1;
  }
  for (int i = N - 2; i < N; i++)
    for (int j = N - 2; j < N; j++)
      score += (abs(grid.pos[i * N + j].r - i) + abs(grid.pos[i * N + j].c - j)) * P;
  return score;
}

void solve()
{
  baseTime = getCycle();
  long long turn = (1LL << (N - 2)) - 1, bestTurn;
  int bestScore = 1e9;
  int count = 0;
  double currentTime = (double)(getCycle() - baseTime) / cyclePerSec;
  double C = timeLimit * 100;
  while (currentTime < timeLimit)
  {
    answer.clear();
    int change = rand() % (N - 2);
    if (turn & (1LL << change))
    {
      turn &= ~(1LL << change);
    }
    else
    {
      turn |= (1LL << change);
    }
    int score = simulation(turn);
    currentTime = (double)(getCycle() - baseTime) / cyclePerSec;
    double forceLine = (timeLimit - currentTime) / C;
    if (score < bestScore)
    {
      bestanswer = answer;
      bestScore = score;
      bestTurn = turn;
      cerr << "Update best score.(" << bestScore << ")" << endl;
    }
    if (bestScore < score && forceLine < (double)rand() / RAND_MAX)
    {
      if (turn & (1LL << change))
      {
        turn &= ~(1LL << change);
      }
      else
      {
        turn |= (1LL << change);
      }
    }
    count++;
  }
  cerr << "N: " << N << endl;
  cerr << "score: " << bestScore << endl;
  cerr << "count: " << count << endl;
  cerr << "time: " << (double)(getCycle() - baseTime) / cyclePerSec << endl;
  cerr << "turn: " << bitset<38>(bestTurn) << endl;
  return;
}

void init()
{
  grid.pos_.resize(N * N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    {
      grid.g_[i][j]--;
      grid.pos_[grid.g_[i][j]] = {i, j};
    }
  return;
}

void input()
{
  cin >> N;
  cin >> P;
  grid.g_.resize(N, vector<int>(N));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
    {
      cin >> grid.g_[i][j];
    }
  return;
}

void output()
{
  ofstream outputfile("out");
  outputfile << bestanswer.size() << endl;
  for (Move i : bestanswer)
  {
    outputfile << i.r << " " << i.c << " " << i.s << " " << i.dir << endl;
  }

  cout << bestanswer.size() << endl;
  for (Move i : bestanswer)
  {
    cout << i.r << " " << i.c << " " << i.s << " " << i.dir << endl;
  }
  return;
}

int main()
{
  input();
  init();
  solve();
  output();
  return 0;
}
