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

string tostring(const ii p) {
    return to_string(p.first) + "_" + to_string(p.second);
}

string tostring(const ii p, const int dir) {
    return tostring(p) + "_" + to_string(dir);
}


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
    cout << endl;
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

bool checkForLoop(vector<string> mat, ii p, int dir, unordered_set<string> vis) {
    while (true) {
        if (vis.find(tostring(p, dir)) != vis.end()) {
            return true;
        }
        vis.insert(tostring(p, dir));

        ii next = ii(p.first + MOVES[dir].first, p.second + MOVES[dir].second);
        if (! isValid(mat, next.first, next.second)) {
            return false;
        }

        if (mat[next.first][next.second] == '#') {
            dir = (dir + 1) % 4;
        }
        else {
            p = next;
        }
    }

    return false;
}

int run(vector<string>& mat, ii p) {
    int dir = getDir(mat[p.first][p.second]);
    mat[p.first][p.second] = '.';

    unordered_set<string> ret;
    unordered_set<string> vis;
    
    while (true) {
        ii next = ii(p.first + MOVES[dir].first, p.second + MOVES[dir].second);
        if (! isValid(mat, next.first, next.second)) {
            break;
        }

        if (mat[next.first][next.second] == '#') {
            vis.insert(tostring(p, dir));
            dir = (dir + 1) % 4;
        }
        else {
            if (mat[next.first][next.second] == '.') {
                mat[next.first][next.second] = '#';
                if (ret.find(tostring(next)) == ret.end() && checkForLoop(mat, p, dir, vis)) {
                    ret.insert(tostring(next));
                }
                mat[next.first][next.second] = '.';
            }
            vis.insert(tostring(p, dir));
            mat[p.first][p.second] = '$';
            p = next;
        }
    }

    return ret.size();
}

ll solve(vector<string>& mat) {
    ll ret = 0;

    ii start = findStart(mat);
    ret = run(mat, start);

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
