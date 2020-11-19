// URL: https://codeforces.com/contest/1432/submission/98184317
// Date: Thu, 12 Nov 2020 17:59:32 +0900
// Language: Kotlin
fun main() {
  val (n, m, d) = readLine()!!.split(" ").map { it.toInt() }
  val c = readLine()!!.split(" ").map { it.toInt() }
  var ans = Array(n) { 0 }
  var now = -1
  var i = 0
  while (i < m) {
    if (i != 0)
      now += c[i - 1] - 1 + d
    else
      now += d
    if (n < now + c[i]) {
      var t = n - 1
      var j = m - 1
      while (i <= j) {
        for (k in 0..(c[j] - 1)) {
          if (ans[t - k] != 0) {
            i = Math.min(i, ans[t - k] - 1)
          }
          ans[t - k] = j + 1
        }
        t -= c[j]
        j--
      }
      break
    }
    for (j in now..(now + c[i] - 1))
      ans[j] = i + 1
    i++
  }
  now += c[m - 1] - 1 + d
  if (now < n) {
    println("NO")
  } else {
    println("YES")
    for (o in 0..n - 1) {
      print(ans[o])
      if (o == n - 1) {
        print("\n")
      } else {
        print(" ")
      }
    }
  }
}
