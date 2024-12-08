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
typedef vector<ii> vii;

#define MAXN    100005
#define MAXK    1000000009
#define MOD     1000000007

unordered_map<char, vii> findAnthenas(vector<string>& mat) {
    unordered_map<char, vii> ret;

    FOR (i, 0, mat.size()) {
        FOR (j, 0, mat[i].size()) {
            if (mat[i][j] == '.') {
                continue;
            }

            ret[mat[i][j]].pb(ii(i, j));
        }
    }

    return ret;
}

string tostring(const ii p) {
    return to_string(p.first) + "_" + to_string(p.second);
}

inline bool isValid(const ii p, const int n, const int m) {
    return 0 <= p.first && p.first < n &&
            0 <= p.second && p.second < m;
}

vector<string> getPs(ii p, const int difx, const int dify, const int n, const int m) {
    vector<string> ret;

    p = ii(p.first + difx, p.second + dify);
    if (isValid(p, n, m)) {
        ret.pb(tostring(p));
    }

    return ret;
}

unordered_set<string> getAntinodes(const unordered_map<char, vii>& anthenas, const int n, const int m) {
    unordered_set<string> ret;

    for (auto [ant, positions] : anthenas) {
        sort(positions.begin(), positions.end());
        FOR (i, 0, positions.size()) {
            FOR (j, i + 1, positions.size()) {
                int difx = positions[j].first - positions[i].first;
                int dify = positions[j].second - positions[i].second;

                vector<string> v = getPs(positions[i], -difx, -dify, n, m);
                ret.insert(v.begin(), v.end());

                v = getPs(positions[j], difx, dify, n, m);
                ret.insert(v.begin(), v.end());
            }
        }
    }

    return ret;
}

ll solve(vector<string>& mat) {
    ll ret = 0;

    unordered_map<char, vii> anthenas = findAnthenas(mat);
    unordered_set<string> antinodes = getAntinodes(anthenas, mat.size(), mat.front().size());
    ret = antinodes.size();

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
