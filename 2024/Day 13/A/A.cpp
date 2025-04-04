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

ll solveDP(const vector<ii>& buttons, unordered_map<int, unordered_map<int, int>>& dp, const ii& p) {
    if (p.first == 0 && p.second == 0) {
        return 0;
    }

    if (p.first < 0 || p.second < 0) {
        return -1;
    }

    if (dp[p.first].find(p.second) != dp[p.first].end()) {
        return dp[p.first][p.second];
    }

    dp[p.first][p.second] = -1;

    ll a = solveDP(buttons, dp, ii(p.first - buttons[0].first, p.second - buttons[0].second));
    ll b = solveDP(buttons, dp, ii(p.first - buttons[1].first, p.second - buttons[1].second));

    if (a != -1) {
        dp[p.first][p.second] = a + 3;
    }
    if (b != -1) {
        if (dp[p.first][p.second] == -1) {
            dp[p.first][p.second] = b + 1;
        }
        else {
            dp[p.first][p.second] = min(a + 3, b + 1);
        }
    }

    return dp[p.first][p.second];
}

ll solve(const vector<vector<ii>>& buttons) {
    ll ret = 0;

    for (const vector<ii>& button : buttons) {
        unordered_map<int, unordered_map<int, int>> dp;

        ll val = solveDP(button, dp, ii(button[2].first, button[2].second));
        if (val != -1) {
            ret += val;
        }
    }

    return ret;
}

int main() { _
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    vector<vector<ii>> buttons;
    string line;
    while (getline(cin, line)) {
        stringstream scin(line);

        string aux;
        char c;
        int x, y;
        vector<ii> v;
        scin >> aux >> aux >> c >> c >> x >> c >> c >> c >> y ;
        v.pb(ii(x, y));

        getline(cin, line);
        scin = stringstream(line);
        scin >> aux >> aux >> c >> c >> x >> c >> c >> c >> y ;
        v.pb(ii(x, y));

        getline(cin, line);
        scin = stringstream(line);
        scin >> aux >> c >> c >> x >> c >> c >> c >> y ;
        v.pb(ii(x, y));

        buttons.pb(v);

        getline(cin, line);
    }

    cout << solve(buttons) << endl;

    return 0;
}
