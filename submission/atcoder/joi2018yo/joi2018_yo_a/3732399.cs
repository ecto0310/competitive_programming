// URL: https://atcoder.jp/contests/joi2018yo/submissions/3732399
// Date: Fri, 07 Dec 2018 19:46:31 +0900
// Language: C# (Mono 4.6.2.0)
using System;
class Program
{
  static void Main(string[] args)
  {
    string[] input = Console.ReadLine().Split(' ');
    int n = int.Parse(input[0]) ,a = int.Parse(input[1]), b = int.Parse(input[2]), c = int.Parse(input[3]), d = int.Parse(input[4]);
    Console.WriteLine(Math.Min((n + a - 1) / a * b, (n + c - 1) / c * d));
  }
}
