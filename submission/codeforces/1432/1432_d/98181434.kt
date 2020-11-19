// URL: https://codeforces.com/contest/1432/submission/98181434
// Date: Thu, 12 Nov 2020 17:16:55 +0900
// Language: Kotlin
fun main() {
  val t = readLine()!!.toInt()
  for (_t in 0..t - 1) {
    val (n, a, b) = readLine()!!.split(" ").map { it.toInt() }
    for (i in 0..n - 1) {
      print("abcdefghijklmnopqrstuvwxyz"[i % b])
    }
    print("\n")
  }
}
