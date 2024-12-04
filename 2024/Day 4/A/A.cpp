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

#define MAXN    100005
#define MAXK    1000000009
#define MOD     1000000007

const string XMAS = "XMAS";
const vector<ii> MOVES = {
    ii(-1, -1),
    ii(-1, 0),
    ii(-1, 1),
    ii(0, -1),
    ii(0, 1),
    ii(1, -1),
    ii(1, 0),
    ii(1, 1)
};

inline bool isValid(const vector<string>& mat, const int& x, const int& y) {
    return 0 <= x && x < mat.size() &&
            0 <= y && y < mat[x].size();
}

ll dfs(const vector<string>& mat, int x, int y) {
    ll ret = 0;

    for (const auto [f, s] : MOVES) {
        int i = 1;
        int xx = x;
        int yy = y;
        for (i = 1; i < XMAS.size(); i ++) {
            xx = xx + f;
            yy = yy + s;

            if (! isValid(mat, xx, yy)) {
                break;
            }
            if (mat[xx][yy] != XMAS[i]) {
                break;
            }
        }

        if (i == XMAS.size()) {
            ret ++;
        }
    }

    return ret;
}

ll solve(vector<string>& mat) {
    ll ret = 0;

    FOR (i, 0, mat.size()) {
        FOR (j, 0, mat[i].size()) {
            if (mat[i][j] == XMAS[0]) {
                ret += dfs(mat, i, j);
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
