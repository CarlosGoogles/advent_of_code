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
typedef vector<is> vis;
typedef unordered_map<string, int> foo;

#define MAXN    100005
#define MAXK    1000000009
#define MOD     1000000007

const vector<ii> MOVES = {
    ii(-1, 0),
    ii(0, 1),
    ii(1, 0),
    ii(0, -1)
};

inline bool isValid(const vector<string>& mat, const int& x, const int& y) {
    return 0 <= x && x < mat.size() &&
            0 <= y && y < mat[x].size();
}

void printMat(const vector<string>& mat) {
    for (const string& row: mat) {
        cout << row << endl;
    }
}

string tostring(const ii p) {
    return to_string(p.first) + "_" + to_string(p.second);
}


ll dfs(const vector<string>& mat, ii p, foo& vis) {
    string s = tostring(p);
    int act = mat[p.first][p.second];
    
    if (act == '9') {
        return 1;
    }

    if (vis.find(s) != vis.end()) {
        return vis[s];
    }

    vis[s] = 0;
    for (ii move : MOVES) {
        ii next = ii(p.first + move.first, p.second + move.second);
        if (! isValid(mat, next.first, next.second)) {
            continue;
        }

        if (mat[next.first][next.second] == act + 1) {
            vis[s] += dfs(mat, next, vis);
        }
    }

    return vis[s];
}

ll solve(const vector<string>& mat) {
    ll ret = 0;

    foo vis;

    for (int i = 0; i < mat.size(); i ++) {
        for (int j = 0; j < mat[i].size(); j ++) {
            if (mat[i][j] == '0') {
                // cout << ret << endl;
                ret += dfs(mat, ii(i, j), vis);
            }
        }
    }

    return ret;
}

int main() { _
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    vector<string> mat;
    string line;
    while (getline(cin, line)) {
        mat.pb(line);
    }

    cout << solve(mat) << endl;

    return 0;
}
