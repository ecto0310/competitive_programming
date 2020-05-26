// URL: https://atcoder.jp/contests/abc153/submissions/9786601
// Date: Mon, 27 Jan 2020 22:33:50 +0900
// Language: Rust (1.15.1)
use std::io;

fn main() {
  let mut input = String::new();
  io::stdin().read_line(&mut input).ok();
  let mut it = input.split_whitespace().map(|n| n.parse().unwrap());
  let (h, a): (i32, i32) = (it.next().unwrap(), it.next().unwrap());
  println!("{}", (h + a - 1) / a);
}
