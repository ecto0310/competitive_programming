// URL: https://codeforces.com/contest/1431/submission/98211863
// Date: Fri, 13 Nov 2020 00:07:08 +0900
// Language: Kotlin
fun main() {
  val t = readLine()!!.toInt()
  for (t_ in 0..t - 1) {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val p = readLine()!!.split(" ").map { it.toInt() }
    var ans = 0
    for (i in n - 1 downTo 0) {
      var sum = 0
      for (j in i..Math.min(n - 1, i + (n - i) / k - 1))
        sum += p[j]
      ans = Math.max(ans, sum)
    }
    println(ans)
  }
}
