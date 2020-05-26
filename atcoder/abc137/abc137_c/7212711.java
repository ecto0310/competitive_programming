// URL: https://atcoder.jp/contests/abc137/submissions/7212711
// Date: Sat, 31 Aug 2019 00:11:56 +0900
// Language: Java8 (OpenJDK 1.8.0)
import java.util.*;

class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String[] s = new String[n];
		for(int i = 0; i < n; i++){
			s[i] = sc.next();
		}
		long ans = 0;
		TreeMap<String,Integer> map = new TreeMap<String,Integer>();
		for(int i = 0; i < n; i++){
			int[] a = new int[10];
			for(int j = 0; j < 10; j++){
				a[j] = s[i].charAt(j);
			}
			Arrays.sort(a);
			String b = "";
			for(int j = 0; j < 10; j++){
				b=b + a[j];
			}
			if(map.containsKey(b)){
              map.put(b,map.get(b)+1);
              ans+=map.get(b);
			}else{
				map.put(b,0);
			}
		}
		System.out.print(ans);
	}
}
