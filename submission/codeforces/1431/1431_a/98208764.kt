// URL: https://codeforces.com/contest/1431/submission/98208764
// Date: Thu, 12 Nov 2020 23:39:13 +0900
// Language: Kotlin
fun main() {
  val t = readLine()!!.toInt()
  for (t_ in 0..t - 1) {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toLong() }
    var ans = 0L
    for (i in a) {
      var cnt = 0
      for (j in a)
        if (i <= j)
          cnt++
      ans = Math.max(ans, i*cnt)
    }
    println(ans)
}
}
