// URL: https://codeforces.com/contest/1211/submission/60225637
// Date: Sun, 08 Sep 2019 00:02:29 +0900
// Language: Kotlin
fun main(args: Array<String>)
{
  val n = readLine()!!.toInt()
  val a = readLine()!!.split(" ").map(String::toInt)
  val m = a.max()
  var it=-1
  if(m!=null)
  {
    for(i in 0..n-1)
      if(a[i]==m)
        it=i
    println(n.toLong()*(m-1)+it+1)
  }
}
