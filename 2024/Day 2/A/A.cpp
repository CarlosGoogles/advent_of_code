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

#define MAXN    100005
#define MAXK    1000000009
#define MOD     1000000007

ll solve(vector<vector<int>>& data) {
    int ret = 0;

    for (const vi& row : data) {
        bool up = row[0] < row[1];
        bool good = true;
        for (int i = 1; i < row.size() && good; i ++) {
            int dif = row[i] - row[i-1];
            if (up) {
                good = (1 <= dif && dif <= 3);
            }
            else {
                good = (-3 <= dif && dif <= -1);
            }
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
