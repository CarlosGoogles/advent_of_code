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

const regex MUL ("mul\\(\\d{1,3},\\d{1,3}\\)");
const regex DO ("do\\(\\)");
const regex DONT ("don\'t\\(\\)");

bool enabled = true;

vis getMatches(const string& text, const regex& pattern) {
    vis ret;
    smatch matches;

    std::sregex_iterator begin(text.begin(), text.end(), pattern);
    std::sregex_iterator end;

    for (auto it = begin; it != end; it ++) {
        std::smatch match = *it;
        ret.pb(is(match.position(), match.str()));
    }

    return ret;
}

ll getMult(string& text) {
    int p = 4;
    ll num1 = 0, num2 = 0;
    
    while (isdigit(text[p])) {
        num1 = num1 * 10 + text[p ++] - '0';
    }
    p ++;

    while (isdigit(text[p])) {
        num2 = num2 * 10 + text[p ++] - '0';
    }

    return num1 * num2;
}

ll solve2(string& line) {
    ll ret = 0;
    vis v;

    vis v2 = getMatches(line, MUL);
    v.insert(v.end(), v2.begin(), v2.end());

    v2 = getMatches(line, DO);
    v.insert(v.end(), v2.begin(), v2.end());

    v2 = getMatches(line, DONT);
    v.insert(v.end(), v2.begin(), v2.end());

    sort(v.begin(), v.end());

    for (auto [_p, s] : v) {
        if (s == "do()") {
            enabled = true;
        }
        else if (s == "don't()") {
            enabled = false;
        }
        else {
            if (enabled) {
                ret += getMult(s);
            }
        }
    }

    return ret;
}

ll solve(vector<string>& lines) {
    ll ret = 0;

    for (string line: lines) {
        ret += solve2(line);
    }

    return ret;
}

int main() { _
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    vector<string> lines;
    string line;
    while (getline(cin, line)) {
        lines.pb(line);
    }

    cout << solve(lines) << endl;

    return 0;
}
