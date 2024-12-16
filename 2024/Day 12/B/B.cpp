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
typedef unordered_map<string, unordered_set<string>> foo;

#define MAXN    100005
#define MAXK    1000000009
#define MOD     1000000007

const vector<ii> MOVES = {
    ii(-1, 0),
    ii(0, 1),
    ii(1, 0),
    ii(0, -1)
};

int vis[150][150];

inline bool isValid(const vector<string>& mat, const int& x, const int& y) {
    return 0 <= x && x < mat.size() &&
            0 <= y && y < mat[x].size();
}

inline bool isValid(const vector<string>& mat, const ii& p) {
    return isValid(mat, p.first, p.second);
}

void printMat(const vector<string>& mat) {
    for (const string& row: mat) {
        cout << row << endl;
    }
}

ii dfs(const vector<string>& mat, ii p) {   
    ii ret = ii(1, 0);

    vis[p.first][p.second] = true;
    char c = mat[p.first][p.second];
    
    vector<ii> next;
    for (const ii& move : MOVES) {
        next.pb(ii(p.first + move.first, p.second + move.second));

        if (!isValid(mat, next.back())) {
            continue;
        }
        if (vis[next.back().first][next.back().second]) {
            continue;
        }
        if (c != mat[next.back().first][next.back().second]) {
            continue;
        }
        ii aux = dfs(mat, next.back());
        ret = ii(ret.first + aux.first, ret.second + aux.second);
    }

    for (int i = 0, j = 1; i < next.size(); i ++, j = (j + 1) % next.size()) {
        if (!isValid(mat, next[i]) && !isValid(mat, next[j])) {
            ret.second ++;
        }
        else if (!isValid(mat, next[i])) {
            char c2 = mat[next[j].first][next[j].second];
            if (c != c2) {
                ret.second ++;
            }
        }
        else if (!isValid(mat, next[j])) {
            char c1 = mat[next[i].first][next[i].second];
            if (c != c1) {
                ret.second ++;
            }
        }
        else {
            char c1 = mat[next[i].first][next[i].second];
            char c2 = mat[next[j].first][next[j].second];
            char c3 = mat[next[i].first][next[j].second];
            char c4 = mat[next[j].first][next[i].second];

            if (c != c1 && c != c2) {
                ret.second ++;
            }
            else if (c == c1 && c == c2 && (c != c3 || c != c4)) {
                ret.second ++;
            }
        }
    }

    return ret;
}

ll solve(const vector<string>& mat) {
    ll ret = 0;

    memset(vis, 0, sizeof(vis));
 
    FOR (i, 0, mat.size()) {
        FOR (j, 0, mat[i].size()) {
            if (vis[i][j]) {
                continue;
            }

            auto [area, perimeter] = dfs(mat, ii(i, j));
            ret += area * perimeter;
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