// URL: https://atcoder.jp/contests/abc139/submissions/7341966
// Date: Wed, 04 Sep 2019 23:26:41 +0900
// Language: Java8 (OpenJDK 1.8.0)
import java.util.Scanner;


public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int sum = 1;
    int ans = 0;
    while(sum<b){
      ans++;
      sum+=a-1;
    }
    System.out.print(ans);
  }
}
