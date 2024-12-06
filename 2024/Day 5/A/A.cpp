#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define EPS 1e-6
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(decltype((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, string> is;
typedef vector<int> vi;

#define MAXN    100005
#define MAXK    1000000009
#define MOD     1000000007

unordered_map<int, vector<int>> buildGraph(const vector<vector<int>>& orders) {
    unordered_map<int, vector<int>> graph;
    
    for (const vector<int>& order : orders) {
        graph[order[1]].pb(order[0]);
    }

    return graph;
}

bool solveList(unordered_map<int, vector<int>> graph, vector<int> list) {
    unordered_set<int> vis;
    for (int act : list) {
        if (vis.find(act) != vis.end()) {
            return false;
        }
        vis.insert(act);
        for (int next : graph[act]) {
            vis.insert(next);
        }
    }

    return true;
}

inline ll addAnswer(const vector<int>& list) {
    return list[list.size() / 2];
}

ll solve(vector<vector<int>>& orders, vector<vector<int>>& lists) {
    ll ret = 0;

    auto graph = buildGraph(orders);
    
    for (vector<int> list : lists) {
        if (solveList(graph, list)) {
            ret += addAnswer(list);
        }
    }

    return ret;
}

int main() { _
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    int num1, num2;
    char c;
    vector<vector<int>> orders;

    string line;
    while (getline(cin, line)) {
        if (line == "") {
            break;
        }

        stringstream scin(line);
        scin >> num1 >> c >> num2;
        orders.pb({num1, num2});
    }

    vector<vector<int>> lists;
    while (getline(cin, line)) {
        stringstream scin(line);
        vector<int> v;

        scin >> num1;
        v.pb(num1);
        while (scin >> c >> num1) {
            v.pb(num1);
        }
        lists.pb(v);
    }

    cout << solve(orders, lists) << endl;

    return 0;
}
