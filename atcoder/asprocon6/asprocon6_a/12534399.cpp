// URL: https://atcoder.jp/contests/asprocon6/submissions/12534399
// Date: Fri, 01 May 2020 04:43:37 +0000
// Language: C++ (GCC 9.2.1)
// sample_code Ver.5.1
//
// このコードをAtCoder上に提出すると予選用データではACを得られますが、
// 決勝用データでは計画終了時刻を超えて、WAとなる可能性があります。
// また、Visualizerで計画を見るとわかりますが、納期遅れペナルティが非常に大きくなっており、
// ほとんどの入力データで0点になるため、改良を施してより高い得点を目指してください。
//
// if this sample code is submitted, "AC" will be got in the input data for qualifying,
// but in the input data for ranking, there is a possibility of production end time over and getting "WA".
// Moreover, you can recognize on the visualizer that the delay penalty of the operation is very large and
// it gets 0 point at almost all the input data, so improve the operation and try to get higher score.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <ctime>

constexpr auto day_sec = 24LL * 60LL * 60LL;
template <typename T>
constexpr std::common_type_t<T, decltype(day_sec)> sec_to_day_down(T sec)
{
  return sec / day_sec;
}
template <typename T>
constexpr std::common_type_t<T, decltype(day_sec)> sec_to_day_up(T sec)
{
  return (sec + day_sec - 1) / day_sec;
}
template <typename T>
constexpr std::common_type_t<T, decltype(day_sec)> day_to_sec(T day)
{
  return day_sec * day;
}

struct Input
{
public:
  struct Header
  {
    int M = 0, I = 0, R = 0, BL = 0, CL = 0;
  } header = {0, 0, 0, 0, 0};
  struct Machine
  {
    int rq = 0, mn = 0;
    std::vector<int> md;
  };
  struct Bom
  {
    int c = 0, ec = 0;
  };
  struct Combi
  {
    int t = 0, cc = 0;
  };
  struct Order
  {
    int r = 0, i = 0, e = 0, d = 0, q = 0, qmin = 0, pr = 0, a = 0;
  };

private:
  std::vector<Machine> machine;                            // machine[m] = {rq, mn, {md_0, md_1, ..., md_(mn-1)}}
  std::vector<std::map<int, Bom>> bom;                     // bom[i][m] = {c, ec}
  std::vector<std::map<std::pair<int, int>, Combi>> combi; // combi[m][{ipre, inext}] = {t, cc}
public:
  std::vector<Order> order;

  void read(std::istream &in = std::cin)
  {
    std::string s;
    in >> s >> header.M >> header.I >> header.R >> header.BL >> header.CL;
    machine.resize(header.M);
    bom.resize(header.I);
    combi.resize(header.M);
    order.resize(header.R);
    for (int c = 0; c < header.M; c++)
    {
      int m, rq, mn;
      in >> s >> m >> rq >> mn;
      machine[m].rq = rq;
      machine[m].mn = mn;
      machine[m].md.resize(mn);
      for (auto &md : machine[m].md)
      {
        in >> md;
      }
    }
    for (int b = 0; b < header.BL; b++)
    {
      int i, m, c, ec;
      in >> s >> i >> m >> c >> ec;
      bom[i][m] = {c, ec};
    }
    for (int c = 0; c < header.CL; c++)
    {
      int m, ipre, inext, t, cc;
      in >> s >> m >> ipre >> inext >> t >> cc;
      combi[m][{ipre, inext}] = {t, cc};
    }
    for (int o = 0; o < header.R; o++)
    {
      int r, i, e, d, q, qmin, pr, a;
      in >> s >> r >> i >> e >> d >> q >> qmin >> pr >> a;
      order[o] = {r, i, e, d, q, qmin, pr, a};
    }
    std::stable_sort(std::begin(order), std::end(order), [](const auto &l, const auto &r) { return l.d < r.d; });
  }

  // return {c, ec};
  auto get_bom(int i, int m) const
  {
    auto it = bom[i].find(m);
    if (it == bom[i].end())
    {
      return std::make_pair(-1, -1); // 生産不能 --- impossible to bake.
    }
    return std::make_pair(it->second.c, it->second.ec);
  }

  // return {t, cc};
  auto get_combi(int m, int ipre, int inext) const
  {
    auto it = combi[m].find({ipre, inext});
    if (it == combi[m].end())
    {
      return std::make_pair(-1, -1); // 生産不能 --- impossible to bake.
    }
    return std::make_pair(it->second.t, it->second.cc);
  }

  // { bool : secが休日期間ではない, long long : 次の休日期間または休日ではない期間までの秒数, 無限なら -1 } のペアを返す。
  // returns pair of { bool : whether sec does not overlap holiday, long long : seconds until the next holiday or operating time. -1 if it is infinity. }
  auto get_machine_next(int m, long long sec) const
  {
    const auto &c = machine[m];
    auto day = sec_to_day_down(sec);
    auto it = std::lower_bound(c.md.begin(), c.md.end(), day);
    auto time = 0LL;
    auto flag = true;
    if (it == c.md.end())
    {
      time = -1LL;
    }
    else if (*it == day)
    {
      flag = false;
      auto day_count = day;
      while (true)
      {
        if (++it == c.md.end())
        {
          time = day_to_sec(day_count + 1) - sec;
          break;
        }
        if (*it != ++day_count)
        {
          time = day_to_sec(day_count) - sec;
          break;
        }
      }
    }
    else
    {
      time = day_to_sec(*it) - sec;
    }
    return std::make_pair(flag, time);
  }

  auto get_rq(int m) const
  {
    return machine[m].rq;
  }
};

struct Output
{
  struct Order
  {
    int r, m, q, t3, t4;
  };
  std::vector<Order> order;
  struct ChangeOver
  {
    int m, t1, t2;
  };
  std::vector<ChangeOver> combi;

  void print(std::ostream &out = std::cout) const
  {
    constexpr auto order_s = "ORDER";
    constexpr auto combi_s = "COMBI";
    constexpr auto delim = '	';
    for (const auto &o : order)
    {
      out << order_s << delim << o.r << delim << o.m << delim << o.q << delim << o.t3 << delim << o.t4 << std::endl;
    }
    for (const auto &c : combi)
    {
      out << combi_s << delim << c.m << delim << c.t1 << delim << c.t2 << std::endl;
    }
  }
};

// t1またはt3を計算するのに使う。t1を計算するときは e = 0 を指定。
// use to calculate t1 or t3. if calculating t1, set e = 0.
auto calc_t1(int m, int pre_time, int need_time, int e, const Input &input)
{
  auto t1 = std::max(e, pre_time);
  while (true)
  {
    auto pair = input.get_machine_next(m, t1);
    auto b = std::move(pair.first);
    auto t_to_next = std::move(pair.second);
    if (t_to_next == -1 || (b && need_time <= t_to_next))
    { // 休日とぶつからない --- not overlap with holiday
      break;
    }
    t1 += static_cast<int>(t_to_next);
  }
  return t1;
}

auto find_next_m_and_t(int m, int i, const Input &input)
{
  auto t3_t4 = 0; // 必要秒数 --- required time
  while (true)
  {
    auto pair = input.get_bom(i, m);
    auto t = std::move(pair.first);
    if (t != -1)
    { // 製造可能 --- possible to bake
      t3_t4 = t;
      break;
    }
    m = (m + 1) % input.header.M; // 次のパン焼き機へ --- go to next machine
  }
  return std::make_pair(m, t3_t4);
}

auto solve(const Input &input)
{
  Output output;
  std::vector<int> ipre(input.header.M, -1);         // 直前の品目。無ければ-1 --- previous item. if nothing, -1.
  std::vector<int> time(input.header.M, 0);          // 直前の割付けの終了時刻 --- the end time of previous assignment.
  std::vector<int> last_quantity(input.header.M, 0); // 直前のバッチの数量 --- the quantity of previous batch.
  for (const auto &o : input.order)
  {
    // qminを満たすようにあらかじめできる限り細かく分割しておく --- split as small as possible to satisfy qmin.
    auto max_sep = o.q / o.qmin;
    std::vector<int> batch_num(max_sep, o.qmin);
    auto q_sum = max_sep * o.qmin;
    auto rest = o.q - q_sum; // あふれた分 --- overflowing

    // パン焼き機は0番目から探す --- find machine from No.0
    auto pair = find_next_m_and_t(min_element(time.begin(), time.end()) - time.begin(), o.i, input);
    auto m = std::move(pair.first);
    auto t3_t4 = std::move(pair.second);

    while (true)
    {
      auto available = input.get_rq(m) - o.qmin;
      if (available * max_sep >= rest)
      { // あふれた分を入れられるかどうか --- whether overflowing can be distributed
        auto i = 0;
        while (rest > 0)
        {
          int cnt = std::min(rest, available);
          batch_num[i++] += cnt;
          rest -= cnt;
        }
        break;
      }
      // 入れられないなら次のパン焼き機へ --- if it is impossible to distribute, go to next machine
      std::tie(m, t3_t4) = find_next_m_and_t(m + 1, o.i, input);
    }

    if (ipre[m] != -1 && ipre[m] != o.i)
    { // 段取り時間 --- setup time
      auto change_t = input.get_combi(m, ipre[m], o.i).first;
      if (change_t != 0)
      {
        auto t1 = calc_t1(m, time[m], change_t, 0, input);
        auto t2 = t1 + change_t;
        time[m] = t2;
        output.combi.push_back({m, t1, t2});
      }
      last_quantity[m] = input.get_rq(m); // 段取りで埋まる --- filled by setup.
    }

    for (auto bat : batch_num)
    { // 焼き時間 --- baking time
      auto t = time[m] - t3_t4;
      // 直前のバッチに入れられるなら入れる --- put into the previous batch if possible.
      if (input.get_rq(m) - last_quantity[m] >= bat && o.e <= t)
      {
        if (output.order.back().r == o.r)
        {
          output.order.back().q += bat;
        }
        else
        {
          output.order.push_back({o.r, m, bat, t, time[m]});
        }
        last_quantity[m] += bat;
        continue;
      }
      // 新規バッチ --- new batch
      auto t3 = calc_t1(m, time[m], t3_t4, o.e, input);
      auto t4 = t3 + t3_t4;
      time[m] = t4;
      output.order.push_back({o.r, m, bat, t3, t4});
      last_quantity[m] = bat;
    }
    ipre[m] = o.i;
  }
  return output;
}

int main()
{
  Input input;
  input.read();
  auto output = solve(input);
  output.print();
  return 0;
}
