#include <bits/stdc++.h>

#define PI 3.14159265358979323846
#define EPS 1e-6
#define INF 1000000000

#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(ll i=ll(a); i<ll(b); i++)
#define RFOR(i, a, b) for(ll i=ll(a)-1; i>=ll(b); i--)
#define FORC(cont, it) for(decltype((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(decltype((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;

#define MAXN    100005
#define MAXK    1000000009
#define MOD     1000000007

struct Range {
    ll a, b, c;
    Range() {
    }

    Range(ll aa, ll bb, ll cc) : a(aa), b(bb), c(cc) {

    }

    bool operator<(const Range& r) const {
        return a < r.a || 
            (a == r.a && c < r.c) ||
            (a == r.a && c == r.c && b == r.b);
    }

    bool check(const ll& val) const {
        return b <= val && val <= b + c;
    }

    ll next(const ll& val) const {
        return a + (val - b);
    }
};

vector<ll> seeds;
vector<Range> range[7];

void read() {
    string line, word;
    getline(cin, line);
    stringstream stream(line);
    
    stream >> word; // seeds:
    while (stream >> word) {
        seeds.pb(stoll(word));
    }

    getline(cin, line);
    getline(cin, line);
    ll lvl = 0;
    while (getline(cin, line)) {
        if (line == "") {
            lvl ++;
            getline(cin, line);
            continue;
        }
        
        stream = stringstream(line);

        while (stream >> word) {
            ll a = stoll(word);
            stream >> word;
            ll b = stoll(word);
            stream >> word;
            ll c = stoll(word);

            range[lvl].pb(Range(a, b, c));
        }

        sort(range[lvl].begin(), range[lvl].end());
    }
}

void dfs(const ll& lvl, const ll& val, ll& ans) {
    if (lvl == 7) {
        ans = min(ans, val);
        return;
    }

    bool b = false;
    for (Range r : range[lvl]) {
        if (r.check(val)) {
            b = true;
            dfs(lvl + 1, r.next(val), ans);
        }
    }

    if (!b)     dfs(lvl + 1, val, ans);
}

int main() { _
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    read();
    ll ans = INF;
    for (ll seed : seeds) {
        dfs(0, seed, ans);
    }

    cout << ans << endl;

    return 0;
}
