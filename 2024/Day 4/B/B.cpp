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

void counts(const vector<string>& mat, const int x, const int y, int& ms, int& ss) {
    if (mat[x][y] == 'M') {
        ms ++;
    } 
    else if (mat[x][y] == 'S') {
        ss ++;
    }
}

bool dfs(const vector<string>& mat, const int x, const int y) {
    int ms = 0;
    int ss = 0;
    
    counts(mat, x-1, y-1, ms, ss);
    counts(mat, x-1, y+1, ms, ss);
    counts(mat, x+1, y-1, ms, ss);
    counts(mat, x+1, y+1, ms, ss);

    if (!(ms == 2 && ss == 2)) {
        return false;
    }

    if (mat[x-1][y-1] == mat[x+1][y+1]) {
        return false;
    }
    return true;
}

ll solve(vector<string>& mat) {
    ll ret = 0;

    FOR (i, 1, mat.size()-1) {
        FOR (j, 1, mat[i].size()-1) {
            if (mat[i][j] == 'A') {
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
