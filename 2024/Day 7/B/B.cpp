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
typedef vector<ll> vi;
typedef vector<vi> vvi;

#define MAXN    100005
#define MAXK    1000000009
#define MOD     1000000007

ll getNext(ll a, ll b) {
    return stoll(to_string(a) + to_string(b));
}

bool solveDP(vector<ll> ops, const ll target, ll sum, const int p) {
    if (p == ops.size()) {
        return target == sum;
    }

    if (target < sum) {
        return false;
    }
    
    return  solveDP(ops, target, sum == 0 ? ops[p] : sum * ops[p],  p+1) ||     // MULT
            solveDP(ops, target, getNext(sum, ops[p]), p+1) ||                  // CONC
            solveDP(ops, target, sum + ops[p], p+1);                            // ADD
}

ll solve(vector<ll>& result, vector<vector<ll>>& operations) {
    ll ret = 0;

    for (int i = 0; i < result.size(); i ++) {
        if (solveDP(operations[i], result[i], 0, 0)) {
            ret += result[i];
        }
    }

    return ret;
}

int main() { _
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    vi result;
    vvi operations;
    string line;
    while (getline(cin, line)) {
        ll num;
        char c;
        stringstream scin(line);

        scin >> num;
        result.pb(num);

        vi v;
        scin >> c;
        while (scin >> num) {
            v.pb(num);
        }
        operations.pb(v);
    }

    cout << solve(result, operations) << endl;

    return 0;
}
