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

ii findStart(const vector<string>& mat) {
    FOR (i, 0, mat.size()) {
        FOR (j, 0, mat[i].size()) {
            if (mat[i][j] != '.' && mat[i][j] != '#') {
                return ii(i, j);
            }
        }
    }

    return ii(0, 0);
}

void printMat(const vector<string>& mat) {
    for (const string& row: mat) {
        cout << row << endl;
    }
}

ll countAns(const vector<string>& mat) {
    ll ret = 0;
    
    for (const string& row: mat) {
        for (char pos : row) {
            ret += pos == 'X';
        }
    }

    // printMat(mat);

    return ret;
}

int getDir(const char c) {
    if (c == '^') {
        return 0;
    }
    if (c == '>') {
        return 1;
    }
    if (c == 'v') {
        return 2;
    }
    return 3;
}

void run(vector<string>& mat, ii p) {
    int dir = getDir(mat[p.first][p.second]);

    mat[p.first][p.second] = 'X';
    while (true) {
        ii next = ii(p.first + MOVES[dir].first, p.second + MOVES[dir].second);
        if (! isValid(mat, next.first, next.second)) {
            return;
        }

        if (mat[next.first][next.second] == '#') {
            dir = (dir + 1) % 4;
        }
        else {
            p = next;
            mat[p.first][p.second] = 'X';
        }
    }
}

ll solve(vector<string>& mat) {
    ll ret = 0;

    ii start = findStart(mat);
    run(mat, start);
    ret = countAns(mat);

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
