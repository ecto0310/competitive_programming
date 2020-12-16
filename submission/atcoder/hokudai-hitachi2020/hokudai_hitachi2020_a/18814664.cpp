// URL: https://atcoder.jp/contests/hokudai-hitachi2020/submissions/18814664
// Date: Thu, 17 Dec 2020 02:36:29 +0900
// Language: C++ (GCC 9.2.1)
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
FILE *log_dest =
    stderr;
using namespace std;
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
    size_t N_EV, C_EV_init, C_EV_max, V_EV_max, Delta_EV_move;
    std::vector<size_t> pos;
    EV_data(std::istream &src){
        src>> N_EV >> C_EV_init >> C_EV_max >> V_EV_max >> Delta_EV_move;
        pos.resize(N_EV);
        for(size_t i = 0; i < N_EV; ++i){
            src >> pos[i];
            --pos[i];
        }
    }
};
struct A{
    graph_data graph;
    grid_data grid;
    EV_data EV;
    double gamma;
    size_t T_max;
    A(std::istream &src):graph(src), grid(src), EV(src){
        for(size_t i = 0; i < grid.N_grid; ++i){
        }
        src >> gamma;
        src>> T_max;
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
    void load(std::istream &src, [[maybe_unused]]size_t C_EV_max = 25000, [[maybe_unused]]size_t V = 225, [[maybe_unused]]size_t MaxDegree = 5, [[maybe_unused]]size_t N_trans_max = 4, [[maybe_unused]]size_t T_last = 900){
        src >> charge;
        src >> u >> v >> dist_from_u >> dist_to_v;
        --u, --v;
        src >> N_adj; a.resize(N_adj);
        for(size_t i = 0; i < N_adj; ++i){
            src >> a[i];
            --a[i];
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
    vector<vector<size_t>> len;
    vector<vector<size_t>> next;
    vector<size_t> nanogrid_pos;
    size_t diameter = 0;
    size_t cover_radius = 0;
    graph_summary(const graph_data& graph, const grid_data& grid) :
        len(graph.V, std::vector<size_t>(graph.V, 1e9)),
        next(graph.V, std::vector<size_t>(graph.V)),
        nanogrid_pos(grid.N_grid) {
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
        for (size_t i = 0; i < V; ++i)
            for (size_t j = 0; j < V; ++j)
                diameter = max(len[i][j], diameter);
        for (size_t i = 0; i < V; ++i) {
            size_t min_len = 1e9;
            for (size_t j = 0; j < nanogrid_pos.size(); ++j)
                min_len = min(min_len, len[i][j]);
            cover_radius = max(cover_radius, min_len);
        }
    }
};
size_t transit_length(const std::vector<size_t>& path, const std::vector<std::vector<size_t>>& min_path_len) {
    size_t len = 0;
    for (size_t i = 1; i < path.size(); ++i)
        len += min_path_len[path[i - 1]][path[i]];
    return len;
}
size_t transit_length(const std::vector<pair<size_t, int>>& path, const std::vector<std::vector<size_t>>& min_path_len) {
    size_t len = 0;
    for (size_t i = 1; i < path.size(); ++i)
        len += min_path_len[path[i - 1].first][path[i].first];
    return len;
}
pair<size_t, size_t> nearest_point(size_t current, const vector<size_t>& points, const graph_summary& gs) {
    size_t len = 1e9, nearest_pos = -1, nearest_index = -1;
    for (size_t i = 0; i < points.size(); ++i)
        if (gs.len[current][points[i]] < len) {
            len = gs.len[current][points[i]];
            nearest_pos = points[i];
            nearest_index = i;
        }
    return { nearest_index, nearest_pos };
}
pair<size_t, size_t> nearest_nanogrid(size_t current, const graph_summary& gs) {
    return nearest_point(current, gs.nanogrid_pos, gs);
}
string path_string(const vector<pair<size_t, int>>& path) {
    string ret;
    for (auto [p, pickup] : path) ret += " -> " + to_string(p + 1) + (pickup != -1 ? "(pickup: " + to_string(pickup) + ")" : "");
    return ret;
}
vector<pair<size_t, int>> find_transit_path_greedy(size_t current,
    const vector<tuple<size_t, size_t, size_t>>& order,
    const graph_summary& gs) {
    for ([[maybe_unused]] auto [from, to, id] : order) {
    }
    vector<pair<size_t, int>> ret; ret.reserve(2 * order.size());
    vector<size_t> pickup_flag(order.size(), 0);
    vector<size_t> index; index.reserve(order.size());
    vector<size_t> candidate; candidate.reserve(2 * order.size());
    size_t cur = current;
    while (1) {
        for (size_t i = 0; i < order.size(); ++i)
            switch (pickup_flag[i]) {
            case 0:
                candidate.push_back(get<0>(order[i]));
                index.push_back(i);
                break;
            case 1:
                candidate.push_back(get<1>(order[i]));
                index.push_back(i);
                break;
            default:;
            }
        if (candidate.size() == 0) break;
        for ([[maybe_unused]]auto p : candidate) ;
        auto [i, pos] = nearest_point(cur, candidate, gs);
        ret.emplace_back(pos, pickup_flag[index[i]] == 0 ? get<2>(order[index[i]]) : -1);
        pickup_flag[index[i]] += 1;
        cur = pos;
        candidate.clear();
        index.clear();
    }
    return ret;
}
size_t path_length_test(size_t insert_point, size_t insert_index, const std::vector<size_t>& path, const std::vector<std::vector<size_t>>& min_path_len) {
    size_t len = insert_index == 0 ? min_path_len[insert_point][path[0]] : 0;
    for (size_t i = 1; i < path.size(); ++i)
        if (insert_index == i)
            len += min_path_len[path[i - 1]][insert_point] + min_path_len[insert_point][path[i]];
        else
            len += min_path_len[path[i - 1]][path[i]];
    len += insert_index == path.size() ? min_path_len[path.back()][insert_point] : 0;
    return len;
}
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
auto minimal_matching(const vector<size_t>& start, const vector<size_t>& goal, const graph_summary& gs) {
    auto minimal_s = start.begin(), minimal_g = goal.begin();
    size_t minimal_len = 1e9;
    for (auto s = start.begin(); s != start.end(); ++s)
        for (auto g = goal.begin(); g != goal.end(); ++g)
            if (gs.len[*s][*g] < minimal_len) {
                minimal_s = s;
                minimal_g = g;
                minimal_len = gs.len[*s][*g];
            }
    return make_pair(minimal_s, minimal_g);
}
template<class... Args>
string strprintf(const char *fmt, const Args & ...args){
    char buf[65536];
    sprintf(buf, fmt, args...);
    return buf;
}
template<class P>
struct strategy :public P {
    const graph_summary& gs;
    vector<list<string>> command_queue;
    strategy(const P& p, const graph_summary& gs) : P(p), gs(gs),
        command_queue(P::EV.N_EV) {}
    virtual void command(const grid_info& g_i, const EV_info& ev_i, const order_info& order_i) = 0;
    virtual void initialize() {
        for (auto& queue : command_queue) queue.clear();
    }
    bool is_free(size_t EV_index) {
        if (command_queue[EV_index].size() > 0) {
            return false;
        }
        return true;
    }
    string dequeue(const EV_info& ev_i) {
        string ret = "";
        for (size_t i = 0; i < ev_i.N_EV; ++i)
            ret += dequeue(i) + "\n";
        return ret;
    }
    string dequeue(size_t EV_index) {
        string ret;
        if (command_queue[EV_index].size() > 0) {
            ret = command_queue[EV_index].front();
            command_queue[EV_index].pop_front();
        }
        else {
            ret = "stay";
        }
        return ret;
    }
    void enqueue(size_t EV_index, const string& cmd) {
        command_queue[EV_index].push_back(cmd);
    }
    void enqueue(size_t EV_index, const string& cmd, size_t repeat) {
        for (size_t i = 0; i < repeat; ++i)
            command_queue[EV_index].push_back(cmd);
    }
    void enqueue(size_t EV_index, list<string>&& cmd_list) {
        command_queue[EV_index].splice(command_queue[EV_index].end(), cmd_list);
    }
};
template<class P>
struct all_stay : strategy<P> {
    all_stay(const P& p, const graph_summary& gs) : strategy<P>(p, gs) {}
    void command(const grid_info&, const EV_info&, const order_info&) {}
};
template<class P>
struct random_walk : strategy<P> {
    using S = strategy<P>;
    std::mt19937_64 engine;
    random_walk(const P& p, const graph_summary& gs) : strategy<P>(p, gs) {}
    void command(const grid_info&, const EV_info& ev_i, const order_info&) {
        for (size_t n = 0; n < ev_i.N_EV; ++n) {
            if (!S::is_free(n)) continue;
            const size_t current = ev_i.c[n].u;
            const size_t safety_energy = S::EV.Delta_EV_move * 50;
            if (auto [_, pos] = nearest_nanogrid(current, S::gs); current != pos) {
                const size_t len_to_charge = S::gs.len[current][pos];
                const int expected_energy = ev_i.c[n].charge - len_to_charge * S::EV.Delta_EV_move;
                if (expected_energy < 0) {
                    S::enqueue(n, "stay", 1000);
                }
                else
                    S::enqueue(n, move_EV(current, pos, S::gs));
                continue;
            }
            else {
                if (ev_i.c[n].charge < safety_energy) {
                    S::enqueue(n, strprintf("charge_from_grid %zu", S::EV.V_EV_max), ceil(1.0 * (safety_energy - ev_i.c[n].charge) / S::EV.V_EV_max));
                    continue;
                }
            }
            uniform_int_distribution<size_t> dice(0, ev_i.c[n].N_adj - 1);
            const size_t goal = dice(engine);
            S::enqueue(n, move_EV(current, ev_i.c[n].a[goal], S::gs));
        }
    }
};
vector<string> split_command(const string &command_pack){
    vector<string> ret;
    stringstream reader(command_pack);
    string line;
    while(getline(reader, line)){
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
    string to_str() const{
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
command parser(const string &command){
    stringstream reader(command);
    string command_str;
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
    setbuf(log_dest, nullptr);
    size_t N_solution = 1;
    A prob(cin);
    std::shared_ptr<strategy<A>> str = nullptr;
    graph_summary gs(prob.graph, prob.grid);
    grid_info grid_i(prob.grid.N_grid);
    EV_info ev_i(prob.EV.N_EV);
    order_info order_i;
    string command_per_turn;
    vector<pair<double, double>> scores; scores.reserve(N_solution);
    for(size_t n = 0; n < N_solution; ++n){
        str.reset(new all_stay<A>(prob, gs));
        // str.reset(new random_walk<A>(prob, gs));
        str->initialize();
        for(size_t t = 0; t < prob.T_max; ++t){
            grid_i.load(cin);
            ev_i.load(cin);
            str->command(grid_i, ev_i, order_i);
            command_per_turn = str->dequeue(ev_i);
            auto command_list = split_command(command_per_turn);
            cout << command_per_turn << flush;
        }
        grid_i.load(cin);
        ev_i.load(cin);
        double Score;
        cin >> Score;
    }
    return 0;
}
