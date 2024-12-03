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
typedef vector<int> vi;

#define MAXN    105
#define MAXK    1000000009
#define MOD     1000000007

int dp[MAXN][2];

inline bool checkDif(const int& l, const int& r) {
    int dif = r - l;
    return (1 <= dif && dif <= 3);
}

void reverse(vi& v) {
    for (int& num : v) {
        num = -num;
    }
}

bool solveDp(const vi& row, const int p, const bool skips) {
    if ((p+1 == row.size()) || (p+2 == row.size() && !skips)) {
        return true;
    }

    if (dp[p][skips] != -1) {
        return dp[p][skips];
    }

    dp[p][skips] = false;
    if (checkDif(row[p], row[p+1])) {
        dp[p][skips] = solveDp(row, p+1, skips);
    }
    if (!skips && checkDif(row[p], row[p+2])) {
        dp[p][skips] = dp[p][skips] || solveDp(row, p+2, true);
    }

    return dp[p][skips];
}

ll solve(vector<vector<int>>& data) {
    int ret = 0;

    for (vi& row : data) {
        bool good = false;
        
        for (int i = 0; i < 2 && !good; i ++) {
            memset(dp, -1, sizeof(dp));
            good = solveDp(row, 0, false) || solveDp(row, 1, true);
            reverse(row);
        }

        ret += good;
    }

    return ret;
}

int main() { _
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    vector<vector<int>> in;

    string line;
    while (getline(cin, line)) {
        stringstream scin(line);

        int num;
        vector<int> inn;
        while (scin >> num) {
            inn.pb(num);
        }
        in.pb(inn);
    }

    cout << solve(in) << endl;

    return 0;
}
