// URL: https://atcoder.jp/contests/hokudai-hitachi2020/submissions/19407919
// Date: Wed, 13 Jan 2021 12:12:16 +0900
// Language: C++ (GCC 9.2.1)
#pragma GCC optimize("unroll-loops")
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <cstdio>
#include <memory>
#include <random>
#include <list>
#include <string>
#include <unistd.h>
#include <algorithm>
#include <array>
#include <chrono>
 
 
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
uint32_t xor64(uint64_t x) {
  x = x ^ (x << 13); x = x ^ (x >> 7);
  return x = x ^ (x << 17);
}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
FILE *log_dest =
    stderr;
//using namespace std;
struct graph_data{
    constexpr static size_t MaxDegree = 5;
    size_t V, E;
    std::map<size_t, std::map<size_t, size_t>> edges;
    graph_data(std::istream &src){
        src >> V >> E;
        for(size_t i = 0; i < E; ++i){
            size_t u, v, d;
            src >> u >> v >> d;
            --u, --v;
            edges[u][v] = d;
            edges[v][u] = d;
        }
        for([[maybe_unused]]auto &[u, connects] : edges){
        }
    }
};
struct grid_data{
    size_t DayType;
    size_t N_div, N_pattern, sigma_ele, Delta_event;
    double p_event;
    std::vector<std::vector<int>> pw_predict;
    size_t N_grid, C_grid_init, C_grid_max, V_grid_max;
    std::vector<size_t> x, pattern;
    grid_data() = default;
    grid_data(const grid_data&) = default;
    grid_data(std::istream &src){
        src >> DayType;
        src >> N_div >> N_pattern >> sigma_ele >> p_event >> Delta_event;
        pw_predict.resize(N_pattern);
        for(size_t i = 0; i < N_pattern; ++i){
            pw_predict[i].resize(N_div);
            for(size_t j = 0; j < N_div; ++j){
                src >> pw_predict[i][j];
            }
        }
        src >> N_grid >> C_grid_init >> C_grid_max >> V_grid_max;
        x.resize(N_grid);
        pattern.resize(N_grid);
        for(size_t i = 0; i < N_grid; ++i){
            src >> x[i] >> pattern[i];
            --x[i];
            --pattern[i];
        }
    }
    grid_data &operator=(const grid_data&) = default;
};
struct EV_data{
    size_t N_EV, C_EV_init, C_EV_max, V_EV_max, N_trans_max, Delta_EV_move;
    std::vector<size_t> pos;
    EV_data(std::istream &src){
        src>> N_EV >> C_EV_init >> C_EV_max >> V_EV_max >> N_trans_max >> Delta_EV_move;
        pos.resize(N_EV);
        for(size_t i = 0; i < N_EV; ++i){
            src >> pos[i];
            --pos[i];
        }
    }
};
struct B{
    graph_data graph;
    grid_data grid;
    EV_data EV;
    double p_const_trans;
    size_t T_last;
    size_t P_trans;
    double gamma;
    int S_ref_ele, S_ref_trans;
    size_t T_max;
    B(std::istream &src):graph(src), grid(src), EV(src){
        for(size_t i = 0; i < grid.N_grid; ++i){
        }
        src >> p_const_trans >> T_last;
        src >> P_trans >> gamma >> S_ref_ele >> S_ref_trans;
        src>> T_max;
    }
};
struct carinfo{
    size_t charge;
    size_t u, v, dist_from_u, dist_to_v;
    size_t N_adj;
    std::vector<size_t> a;
    size_t N_order;
    std::vector<size_t> o;
    void load(std::istream &src, [[maybe_unused]]size_t C_EV_max = 25000, [[maybe_unused]]size_t V = 225, [[maybe_unused]]size_t MaxDegree = 5, [[maybe_unused]]size_t N_trans_max = 4, [[maybe_unused]]size_t T_last = 900){
        src >> charge;
        src >> u >> v >> dist_from_u >> dist_to_v;
        --u, --v;
        src >> N_adj; a.resize(N_adj);
        for(size_t i = 0; i < N_adj; ++i){
            src >> a[i];
            --a[i];
        }
        src >> N_order; o.resize(N_order);
        for(size_t i = 0; i < N_order; ++i){
            src >> o[i];
            --o[i];
        }
    }
};
struct grid_info{
    size_t N_grid;
    std::vector<size_t> x, y;
    std::vector<int> pw_actual;
    std::vector<size_t> pw_excess, pw_buy;
    grid_info() = default;
    grid_info(size_t N_grid)
        :N_grid(N_grid), x(N_grid), y(N_grid), pw_actual(N_grid), pw_excess(N_grid), pw_buy(N_grid){}
    void load(std::istream &src, [[maybe_unused]]size_t V = 225, [[maybe_unused]]size_t C_grid_max = 50000){
        for(size_t i = 0; i < N_grid; ++i){
            src >> x[i] >> y[i] >> pw_actual[i] >> pw_excess[i] >> pw_buy[i];
            --x[i];
        }
    }
};
std::ostream &operator<<(std::ostream &dest, const grid_info &i){
    dest << "\tGrid info:\n";
    for(size_t j = 0; j < i.N_grid; ++j)
        dest << "\t\tx: " << i.x[j] << ", y: " << i.y[j] << ", actual: " << i.pw_actual[j] << ", excess: " << i.pw_excess[j] << ", buy: " << i.pw_buy[j] << "\n";
    return dest;
}
struct EV_info{
    size_t N_EV;
    std::vector<carinfo> c;
    EV_info() = default;
    EV_info(size_t N_EV)
        :N_EV(N_EV), c(N_EV){}
    void load(std::istream &src){
        for(size_t i = 0; i < N_EV; ++i){
            c[i].load(src);
        }
    }
};
std::ostream &operator<<(std::ostream &dest, const EV_info &i){
    dest << "\tEV info:\n";
    for(size_t j = 0; j < i.N_EV; ++j)
        dest << "\t\tcar " << j << "\n";
    return dest;
}
struct order_info{
    size_t N_order;
    std::vector<size_t> id, w, z, state, time;
    order_info() = default;
    void load(std::istream &src, [[maybe_unused]]size_t V = 225, [[maybe_unused]]size_t T_last = 900){
        src >> N_order;
        id.resize(N_order);
        w.resize(N_order);
        z.resize(N_order);
        state.resize(N_order);
        time.resize(N_order);
        for(size_t i = 0; i < N_order; ++i){
            src >> id[i] >> w[i] >> z[i] >> state[i] >> time[i];
            --w[i], --z[i];
        }
    }
};
std::ostream &operator<<(std::ostream &dest, const order_info &i){
    dest << "\tOrder info: " << i.N_order << " orders left\n";
    for(size_t j = 0; j < i.N_order; ++j)
        dest << "\t\tid: " << i.id[j] << ", departure: " << i.w[j] << ", arrival: " << i.z[j] << ", state: " << i.state[j] << ", ordered at: " << i.time[j] << "\n";
    return dest;
}
struct graph_summary {
    std::vector<std::vector<size_t>> len;
    std::vector<std::vector<size_t>> next;
    std::vector<size_t> nanogrid_pos;
    std::vector<size_t> nearnano;
    size_t diameter = 0;
    size_t cover_radius = 0;
    graph_summary(const graph_data& graph, const grid_data& grid) :
        len(graph.V, std::vector<size_t>(graph.V, 1e9)),
        next(graph.V, std::vector<size_t>(graph.V)),
        nanogrid_pos(grid.N_grid), nearnano(graph.V) {
        const size_t V = graph.V;
        for (size_t i = 0; i < V; ++i)
            len[i][i] = 0;
        for (size_t i = 0; i < V; ++i)
            for (size_t j = 0; j < V; ++j)
                next[i][j] = j;
        for (const auto& [u, u_edges] : graph.edges)
            for (const auto& [v, length] : u_edges) {
                len[u][v] = length;
                len[v][u] = length;
            }
        for (size_t k = 0; k < V; ++k)
            for (size_t i = 0; i < V; ++i)
                for (size_t j = 0; j < V; ++j)
                    if (len[i][j] > len[i][k] + len[k][j]) {
                        len[i][j] = len[i][k] + len[k][j];
                        next[i][j] = next[i][k];
                    }
        nanogrid_pos = grid.x;
        for(size_t i = 0; i < V; i++){
            size_t l = 1e9;
            for(size_t j = 0; j < nanogrid_pos.size(); j++){
                if(chmin(l, len[i][nanogrid_pos[j]])){
                    nearnano[i] = nanogrid_pos[j];
                }
            }
        }
 
        for (size_t i = 0; i < V; ++i)
            for (size_t j = 0; j < V; ++j)
                diameter = std::max(len[i][j], diameter);
        for (size_t i = 0; i < V; ++i) {
            size_t min_len = 1e9;
            for (size_t j = 0; j < nanogrid_pos.size(); ++j)
                min_len = std::min(min_len, len[i][nanogrid_pos[j]]);
            cover_radius = std::max(cover_radius, min_len);
        }
 
    }
};
 
 
struct action : std::list<std::string> {};
struct move_EV : action {
    move_EV(size_t current, size_t goal, const graph_summary& gs) {
        for (size_t cur = current; cur != goal; cur = gs.next[cur][goal]) {
            const size_t next = gs.next[cur][goal];
            for (size_t count = 0; count < gs.len[cur][next]; ++count)
                this->push_back("move " + std::to_string(next + 1));
        }
    }
    move_EV(size_t current, const std::vector<size_t>& path, const graph_summary& gs) {
        size_t cur = current;
        for (size_t goal : path)
            for (; cur != goal; cur = gs.next[cur][goal]) {
                const size_t next = gs.next[cur][goal];
                for (size_t count = 0; count < gs.len[cur][next]; ++count)
                    this->push_back("move " + std::to_string(next + 1));
            }
    }
};
template<class... Args>
std::string strprintf(const char *fmt, const Args & ...args){
    char buf[65536];
    sprintf(buf, fmt, args...);
    return buf;
}
template<class P>
struct strategy :public P {
    const graph_summary& gs;
    std::vector<std::list<std::string>> command_queue;
    strategy(const P& p, const graph_summary& gs) : P(p), gs(gs),
        command_queue(P::EV.N_EV) {}
    virtual void command(grid_info& g_i, const EV_info& ev_i, const order_info& order_i, const size_t time) = 0;
    virtual void initialize() {
        for (auto& queue : command_queue) queue.clear();
    }
    bool is_free(size_t EV_index) {
        if (command_queue[EV_index].size() > 0) {
            return false;
        }
        return true;
    }
    std::string dequeue(const EV_info& ev_i) {
        std::string ret;
        for (size_t i = 0; i < ev_i.N_EV; ++i)
            ret += dequeue(i) + "\n";
        return ret;
    }
    std::string dequeue(size_t EV_index) {
        std::string ret;
        if (command_queue[EV_index].size() > 0) {
            ret = command_queue[EV_index].front();
            command_queue[EV_index].pop_front();
        }
        else {
            ret = "stay";
        }
        return ret;
    }
    void enqueue(size_t EV_index, const std::string& cmd) {
        command_queue[EV_index].emplace_back(cmd);
    }
    void enqueue(size_t EV_index, const std::string& cmd, size_t repeat) {
        for (size_t i = 0; i < repeat; ++i)
            command_queue[EV_index].emplace_back(cmd);
    }
    void enqueue(size_t EV_index, std::list<std::string>&& cmd_list) {
        command_queue[EV_index].splice(command_queue[EV_index].end(), cmd_list);
    }
};
 
struct KKT89 : strategy<B>{
    std::set<size_t> assigned_order;
    KKT89(const B& b, const graph_summary& gs) : strategy<B>(b, gs) {}
    void initialize() {
        strategy::initialize();
        assigned_order.clear();
    }
    void command(grid_info& gv_i, const EV_info& ev_i, const order_info& order_i, const size_t time) {
        for (size_t n = 0; n < ev_i.N_EV; ++n) {
            if (!is_free(n)) continue;
            const size_t current = ev_i.c[n].u;
            size_t safety_energy = EV.C_EV_max * 3 / 6;
            if(grid.DayType >= 2) safety_energy = EV.C_EV_max * 3/ 5;
            if (auto pos = gs.nearnano[current]; current != pos) {
                const size_t len_to_charge = gs.len[current][pos];
                const int expected_energy = ev_i.c[n].charge - len_to_charge * EV.Delta_EV_move;
                if (expected_energy < 0 or time > 950) {
                    enqueue(n, "stay", 1000);
                }
                else
                    enqueue(n, move_EV(current, pos, gs));
                continue;
            }
 
            else {
 
            }
 
 
            std::vector<size_t> unassigned_order;
            for (size_t i = 0; i < order_i.N_order; ++i)
                if (assigned_order.count(order_i.id[i]) == 0)
                    unassigned_order.emplace_back(i);
 
            std::sort(unassigned_order.begin(), unassigned_order.end(), [&](auto i, auto j){
                auto cur = current;
                const size_t order_index_i = i;
                const size_t fi = order_i.w[order_index_i];
                const size_t order_index_j = j;
                const size_t fj = order_i.w[order_index_j];
                if(gs.len[cur][fi] == gs.len[cur][fj]) return i < j;
                else return gs.len[cur][fi] < gs.len[cur][fj];
            });
 
            //std::shuffle(unassigned_order.begin(), unassigned_order.end(), rnd);
 
            auto solve=[&]()->void{
                size_t lst = 0;
                std::vector<std::tuple<size_t, size_t, size_t>> assign_order;
                const int max_size = 100;
                int sz = std::min((int)unassigned_order.size(), max_size);
 
                size_t min_len = 1 << 30;
                std::array<int, 4> a = {0, 0, 0, 0};
                std::array<std::pair<int, int>, 8> b, p;
 
                auto create_path = [&](const std::array<std::pair<int,int>, 8> &b)->std::vector<std::pair<size_t, int>>{
                    std::vector<std::pair<size_t, int>> ret; ret.reserve(b.size());
                    for(auto [x, t]:b){
                        const size_t order_index = unassigned_order[x];
                        const size_t from = order_i.w[order_index];
                        const size_t to = order_i.z[order_index];
                        if(t == 1){
                            ret.emplace_back(to, -1);
                        }else{
                            ret.emplace_back(from, order_i.id[order_index]);
                        }
                    }
                    return ret;
                };
 
                auto jupi_loves_kkt = [&](const size_t cur, const size_t end)->size_t{
                    size_t ret = 0;
                    const size_t order_index = unassigned_order[end];
                    const size_t from = order_i.w[order_index];
                    const size_t to = order_i.z[order_index];
                    ret += gs.len[cur][from];
                    ret += gs.len[from][to];
                    return ret;
                };
 
                {
                    std::vector<std::pair<int,int>> candidate; candidate.reserve(8);
                    for(a[0] = 0 ;a[0] < (int)sz; a[0]++){
                        if(min_len <= jupi_loves_kkt(current, a[0])) continue;
                        for(a[1] = a[0] + 1 ; a[1] < (int)sz; a[1]++){
                            if(min_len <= jupi_loves_kkt(current, a[1])) continue;
                            for(a[2] = a[1] + 1; a[2] < (int)sz; a[2]++){
                                if(min_len <= jupi_loves_kkt(current, a[2])) continue;
                                for(a[3] = a[2] + 1; a[3] < (int)sz; a[3]++){
                                    if(min_len <= jupi_loves_kkt(current, a[3])) continue;
                                    size_t len = 0;
                                    candidate.clear();
                                    {
                                        size_t cur = current;
                                        for(size_t i = 0; i < 4; i++){
                                            candidate.emplace_back(a[i], 0);
                                        }
                                        //if(candidate.size() != 4) assert(false);
                                        size_t cnt = 0;
                                        while(not candidate.empty()){
                                            size_t min = 1e9;
                                            std::pair<int, int> idx;
                                            for(auto &[e, t] : candidate){
 
                                                size_t ti = 0;
                                                if(t == 0){
                                                    ti = order_i.w[unassigned_order[e]];
                                                }else{
                                                    ti = order_i.z[unassigned_order[e]];
                                                }
                                                if(chmin(min,gs.len[cur][ti])){
                                                    idx = {e, t};
                                                }
                                            }
                                            b[cnt] = idx;
                                            candidate.erase(std::find(candidate.begin(),candidate.end(),idx));
                                            if(idx.second == 0){
                                                candidate.emplace_back(idx.first, 1);
                                            }
                                           if(idx.second == 0){
                                                size_t nxt = order_i.w[unassigned_order[idx.first]];
                                                len += gs.len[cur][nxt];
                                                cur = order_i.w[unassigned_order[idx.first]];
                                            }else{
                                                size_t nxt = order_i.z[unassigned_order[idx.first]];
                                                len += gs.len[cur][nxt];
                                                cur = order_i.z[unassigned_order[idx.first]];
                                                if(cnt == 7){
                                                    len += gs.len[cur][gs.nearnano[cur]];
                                                }
                                            }
                                            if(len > min_len) break;
                                            cnt += 1;
                                        }
 
                                    }
                                    if(chmin(min_len, len)){
                                        p = b;
                                    }
                                }
                            }
                        }
                    }
                }
                for(auto[x, t] : p){
                    const size_t order_index = unassigned_order[x];
                    const size_t to = order_i.z[order_index];
                    lst = to;
                    assigned_order.insert(order_i.id[order_index]);
                }
                auto path = create_path(p);
                //std::vector<size_t> transit; transit.reserve(path.size() + 1);
                //const size_t expected_transit_length = transit_length(path, gs.len) + gs.len[current][path[0].first];
                auto pos = gs.nearnano[lst];
                //if(lst != path.back().first) assert(false);
                size_t expect_time = min_len + 4;
                if (ev_i.c[n].charge < (min_len + gs.len[lst][pos]) * EV.Delta_EV_move) {
                    if(false and grid.DayType >= 2) expect_time += ((min_len + gs.len[lst][pos]) * EV.Delta_EV_move - ev_i.c[n].charge) / (EV.V_EV_max * 3 / 5) + 1;
                    else expect_time += ((min_len + gs.len[lst][pos]) * EV.Delta_EV_move - ev_i.c[n].charge) / (EV.V_EV_max) + 1;
                }
                if(expect_time >= 1000 - time) return;
                if (ev_i.c[n].charge < (min_len + gs.len[lst][pos]) * EV.Delta_EV_move) {
                    if(false and grid.DayType >= 2) enqueue(n, strprintf("charge_from_grid %zu", EV.V_EV_max * 3 / 5), ((min_len + gs.len[lst][pos]) * EV.Delta_EV_move - ev_i.c[n].charge) / (EV.V_EV_max * 3 / 5) + 1);
                    else enqueue(n, strprintf("charge_from_grid %zu", EV.V_EV_max), ((min_len + gs.len[lst][pos]) * EV.Delta_EV_move - ev_i.c[n].charge) / (EV.V_EV_max) + 1);
                }
 
                size_t cur = current;
                for (auto [to, pick_up] : path) {
                    enqueue(n, move_EV(cur, to, gs));
                    if (pick_up != -1) enqueue(n, strprintf("pickup %d", pick_up));
                    cur = to;
                }  
            };
            if(unassigned_order.size() >= 80) solve();
            //else if(time > 500 and unassigned_order.size() >= 70) solve();
            else if(time > 700 and unassigned_order.size() >= 60) solve();
            else if(time > 800 and unassigned_order.size() >= 50) solve();
            else if(time > 850 and unassigned_order.size() >= 30) solve();
            else if(time > 900 and unassigned_order.size() >= 4) solve();
            else if (ev_i.c[n].charge < safety_energy) {
                size_t pos = gs.nearnano[current];
                size_t y = 0;
                size_t idx = 0;
                for(size_t i = 0; i < gv_i.N_grid; i++){
                    if(gv_i.x[i] == pos) {
                        idx = i;
                        y = gv_i.y[i];
                        break;
                    }
                }
                if(y > 0){
                    size_t dif = std::min({EV.V_EV_max, y * 4 / 5, safety_energy - ev_i.c[n].charge});
                    if(dif == 0) continue;
                    gv_i.y[idx] -= dif;
                    enqueue(n, strprintf("charge_from_grid %zu", dif));
                }
            }else{
                size_t pos = gs.nearnano[current];
                size_t y = 0;
                size_t idx = 0;
                for(size_t i = 0; i < gv_i.N_grid; i++){
                    if(gv_i.x[i] == pos) {
                        idx = i;
                        y = gv_i.y[i];
                        break;
                    }
                }
 
                if(y + EV.V_EV_max < grid.C_grid_max * 4 / 5)
                {
                    size_t dif = std::min(EV.V_EV_max, ev_i.c[n].charge - safety_energy);
                    if(dif == 0) continue;
                    gv_i.y[idx] += dif;
                    enqueue(n, strprintf("charge_to_grid %zu", dif));
                }
 
            }
        }
    }
};
 
std::vector<std::string> split_command(const std::string &command_pack){
    std::vector<std::string> ret;
    std::stringstream reader(command_pack);
    std::string line;
    while(std::getline(reader, line)){
        if(line == "") continue;
        else ret.emplace_back(line);
    }
    return ret;
}
enum command_type{
    stay,
    move,
    pickup,
    charge_from_grid,
    charge_to_grid,
    invalid_command
};
struct command{
    command_type type;
    size_t val;
    command(command_type type, size_t val) : type(type), val(val){}
    std::string to_str() const{
        switch (type)
        {
        case command_type::stay:
            return strprintf("stay");
        case command_type::move:
            return strprintf("move %zu", val);
        case command_type::pickup:
            return strprintf("pickup %zu", val);
        case command_type::charge_from_grid:
            return strprintf("charge_from_grid %zu", val);
        case command_type::charge_to_grid:
            return strprintf("charge_to_grid %zu", val);
        default:
            break;
        }
        return "";
    }
};
command parser(const std::string &command){
    std::stringstream reader(command);
    std::string command_str;
    size_t value;
    reader >> command_str >> value;
    if (command_str == "stay") {
        return { command_type::stay, 0 };
    }else if (command_str == "move") {
        return { command_type::move, value};
    }else if (command_str == "pickup") {
        return { command_type::pickup, value };
    }else if (command_str == "charge_from_grid") {
        return { command_type::charge_from_grid, value};
    }else if (command_str == "charge_to_grid") {
        return { command_type::charge_to_grid, value };
    }
    return {invalid_command, (size_t)-1};
}
int main(){
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    setbuf(log_dest, nullptr);
    size_t N_solution = 1;
    std::cin >> N_solution;
    B prob(std::cin);
    std::shared_ptr<strategy<B>> str = nullptr;
    graph_summary gs(prob.graph, prob.grid);
    grid_info grid_i(prob.grid.N_grid);
    EV_info ev_i(prob.EV.N_EV);
    order_info order_i;
    std::string command_per_turn;
    std::vector<std::pair<double, double>> scores; scores.reserve(N_solution);
    for(size_t n = 0; n < N_solution; ++n){
        // str.reset(new all_stay<B>(prob, gs));
        // str.reset(new random_walk<B>(prob, gs));
        // str.reset(new transport_only_0(prob, gs));
        str.reset(new KKT89(prob, gs));
        str->initialize();
        for(size_t t = 0; t < prob.T_max; ++t){
            grid_i.load(std::cin);
            ev_i.load(std::cin);
            order_i.load(std::cin);
            str->command(grid_i, ev_i, order_i, t);
            command_per_turn = str->dequeue(ev_i);
            auto command_list = split_command(command_per_turn);
            std::cout << command_per_turn << std::flush;
        }
        grid_i.load(std::cin);
        ev_i.load(std::cin);
        order_i.load(std::cin);
        double S_trans, S_ele;
        std::cin >> S_trans >> S_ele;
    }
    return 0;
}
