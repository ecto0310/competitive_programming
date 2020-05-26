// URL: https://codeforces.com/contest/1211/submission/60229209
// Date: Sun, 08 Sep 2019 00:57:19 +0900
// Language: Kotlin
fun main(args: Array<String>)
{
  val (n, k) = readLine()!!.split(" ").map { it.toInt() }
  var list = mutableListOf<Triple<Long, Long, Long>>(Triple(0, 0, 0))
  for (i in 0..n-1)
  {
    val (a, b, c) = readLine()!!.split(" ").map { it.toLong() }
    list.add(Triple(a, b, c))
  }
  var ans=0L
  var cnt=0L
  for(i in 1..n)
  {
    ans+=list[i].third*list[i].first
    cnt+=list[i].first
  }
  if(k<cnt)
  { 
    println(-1)
    return
  }
  list.sortBy{ it.third }
  for(i in 1..n)
  {
    if(k-cnt<=list[i].second-list[i].first)
    {
      ans+=list[i].third*(k-cnt)
      cnt+=k-cnt
      break
    }
    else
    {
      ans+=list[i].third*(list[i].second-list[i].first)
      cnt+=list[i].second-list[i].first
    }
  }
  if(cnt==k.toLong())
    println(ans)
  else
    println(-1)
}
