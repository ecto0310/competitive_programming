// URL: https://atcoder.jp/contests/abc088/submissions/2180591
// Date: Sun, 11 Mar 2018 01:22:33 +0900
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int H,W;
  string s[50];
  cin>> H>> W;
  for(int i=0;i<H;i++)cin>> s[i];
  
  int ret=H*W;
  int far[50][50];
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)far[i][j]=-1;
  int mx[4]={0,0,-1,+1};
  int my[4]={-1,1,0,0};
  queue<pair<int,int>> que;
  que.push(pair<int,int>(0,0));
  far[0][0]=0;
  while(que.size())
  {
    pair<int,int> p=que.front();que.pop();
    for(int i=0;i<4;i++)
    {
      int x=p.first+mx[i];
      int y=p.second+my[i];
      if(x>=0&&x<H&&y>=0&&y<W&&s[x][y]!='#'&&far[x][y]==-1)
      {
        far[x][y]=far[p.first][p.second]+1;
        que.push(pair<int,int>(x,y));
      }
    }
  }
  int black=0;
  for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(s[i][j]=='#')black++;
  ret-=black+far[H-1][W-1]+1;
  if(far[H-1][W-1]==-1)ret=-1;
  cout<< ret<< endl;
  return 0;
}
