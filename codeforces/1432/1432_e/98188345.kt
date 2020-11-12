// URL: https://codeforces.com/contest/1432/submission/98188345
// Date: Thu, 12 Nov 2020 18:58:14 +0900
// Language: Kotlin
fun main() {
  val t = readLine()!!.toInt()
  for (t_ in 0..t - 1) {
    val tmp = readLine()!!.split(" ").map { it.toLong() }
    val n = tmp[0].toInt()
    var k = tmp[1]
    val s = readLine()!!
    var ans = Array<Char>(n) { '0' }
    var pos = 0
    for (i in 0..n - 1) ans[i] = s[i]
    for (i in 0..n - 1) {
        if (k == 0L) break
        while (pos <n && ans[pos] == '0')pos++
        if (ans[i] == '0' && pos <i) {
          if (i - pos <= k) {
            k -= i - pos
            ans[pos] = '0'
            ans[i] = '1'
          } else {
            ans[i - k.toInt()] = '0'
            ans[i] = '1'
            k = 0
          }
        }
    }
    println(ans.joinToString(""))
  }
}
