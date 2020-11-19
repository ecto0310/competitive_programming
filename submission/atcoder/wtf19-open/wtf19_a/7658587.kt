// URL: https://atcoder.jp/contests/wtf19-open/submissions/7658587
// Date: Sun, 22 Sep 2019 23:05:07 +0900
// Language: Kotlin (1.0.0)
fun main(args: Array<String>)
{
  val (n,k) = readLine()!!.split(" ").map(String::toInt)
  var a:MutableList<Int> = readLine()!!.split(" ").map(String::toInt).toMutableList()
  val ans = mutableListOf<Int>()
  var ok=true
  var now = -1
  var size=0
  for(i in 0..k)
  {
    var pos= -1
    var mi =1e9.toInt()
    for(j in 0..n-1)
      if(j!=now&& a[j]<=mi)
      {
        pos=j
        mi=a[j]
      }
    for(j in 0..n-1)
      if(j!=now&& j!=pos)
      {
        ans.add(j+1)
        size++
        a[j]--
        if(a[j]<0)
          ok=false
      }
    ans.add(pos+1)
        size++
    a[pos]--
    if(a[pos]<0)
      ok=false
    now= pos
  }
  if(ok)
  {
    println(size)
    for(i in 0..size-1)
    {
      print(ans[i])
      if(i!=size-1)
        print(" ")
      else println("")
    }
  }
  else
    println(-1)
}
