// URL: https://codeforces.com/contest/1432/submission/98180803
// Date: Thu, 12 Nov 2020 17:07:33 +0900
// Language: Kotlin
fun main() {
  val t = readLine()!!.toInt()
  for (_t in 0..t - 1) {
  val q = readLine()!!.toInt()
  val a = readLine()!!.split(" ").map(String::toInt)
  var sum = 0
  for (i in 0..q - 1) {
    sum += a[i]
  }
  println((sum + q - 1) / q)
}
}
