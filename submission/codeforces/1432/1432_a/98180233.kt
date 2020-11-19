// URL: https://codeforces.com/contest/1432/submission/98180233
// Date: Thu, 12 Nov 2020 16:58:09 +0900
// Language: Kotlin
fun main() {
  val n = readLine()!!.toInt()
  for (i in 0..n - 1) {
    val (a, b) = readLine()!!.split(" ").map { it.toInt() }
    println(a + b)
  }
}
