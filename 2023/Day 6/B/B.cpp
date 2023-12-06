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

vector<ll> vals[2];

void readInput() {
    string line, word;
    
    FOR (i, 0, 2) {
        getline(cin, line);
        stringstream stream(line);
        stream >> word; // Time:
        string word2;
        while (stream >> word) {
            word2 += word;
        }
        vals[i].pb(stoll(word2));
    }
}

int solve() {
    ll ret = 1;
    FOR (i, 0, vals[0].size()) {
        long double b = -vals[0][i];
        long double c = vals[1][i];

        long double d = b*b - 4*1*c;
        d = sqrt(d);

        long double v1 = (-b - d) / 2;
        long double v2 = (-b + d) / 2;

        int b1 = ceil(v1);
        int b2 = floor(v2);
        if (abs(b1 - v1) < EPS) b1 ++;
        if (abs(b2 - v2) < EPS) b2 --;

        if (b2 <= b1)   continue;
        else {
            ret *= (b2 - b1 + 1);
        }
    }

    return ret;
}

int main() { _
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    readInput();

    cout << solve() << endl;

    return 0;
}
