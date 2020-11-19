// URL: https://atcoder.jp/contests/abc137/submissions/7242283
// Date: Sun, 01 Sep 2019 16:44:51 +0900
// Language: Kotlin (1.0.0)
import java.util.*

fun main(args: Array<String>) {
  val n = readLine()!!.toInt()
  val m = ArrayList<String>()
  for (i in 0..n-1) m.add(readLine()!!.toCharArray().sorted().joinToString(""))
  var ans = 0L
  val cnt = mutableMapOf<String,Int>()
  for (i in 0..n-1)
  {
    ans += cnt[m[i]]?.toLong() ?: 0
    cnt[m[i]] = (cnt[m[i]]?: 0) + 1
  }
  println(ans)
}
