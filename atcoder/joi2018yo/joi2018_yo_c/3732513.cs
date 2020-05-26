// URL: https://atcoder.jp/contests/joi2018yo/submissions/3732513
// Date: Fri, 07 Dec 2018 20:18:57 +0900
// Language: C# (Mono 4.6.2.0)
using System;
class Program
{

  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int h = int.Parse(input[0]), w = int.Parse(input[1]);
    int[, ] a = new int[h, w];
    for (int i = 0; i < h; i++)
    {
      string[] ai = Console.ReadLine().Split(' ');
      for (int j = 0; j < w; j++)
        a[i, j] = int.Parse(ai[j]);
    }
    int ans = 1000000000;
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
      {
        int tmp = 0;
        for (int k = 0; k < h; k++)
          for (int l = 0; l < w; l++)
            tmp += Math.Min(Math.Abs(i - k), Math.Abs(j - l)) * a[k, l];
        ans = Math.Min(ans,tmp);
      }
    Console.WriteLine(ans);
  }
}
