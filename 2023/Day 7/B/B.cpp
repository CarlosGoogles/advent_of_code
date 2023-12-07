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

map<char, char> MAPPING = {
    {'J', 'A'},
    {'2', 'B'},
    {'3', 'C'},
    {'4', 'D'},
    {'5', 'E'},
    {'6', 'F'},
    {'7', 'G'},
    {'8', 'H'},
    {'9', 'I'},
    {'T', 'J'},
    {'Q', 'K'},
    {'K', 'L'},
    {'A', 'M'},
};

struct Hand {
    int arr[6] = {0};
    map<char, int> m;
    string s;
    int bid;

    Hand(string& ss, const int& bid) : s(ss), bid(bid) {
        for (char& c : s) {
            c = MAPPING[c];
            m[c] ++;
        }

        int js = 0;
        for (auto p : m) {
            if (p.first == 'A') {
                js += p.second;
                continue;
            }
            arr[p.second] ++;
        }

        if (js == 0)    return;
        if (isFour()) {
            arr[4] --;
            arr[5] ++;
        }
        else if (isThree()) {
            arr[3] --;
            arr[3+js] ++;
        }
        else if (is2Pair()) {
            arr[2] --;
            arr[3] ++;
        }
        else if (isPair()) {
            arr[2] --;
            arr[2+js] ++;
        }
        else if (js == 5) {
            arr[5] = 1;
        }
        else {
            arr[1] --;
            arr[1+js] ++;
        }
    }

    bool isFive() const {
        return arr[5];
    }

    bool isFour() const {
        return arr[4];
    }

    bool isFull() const {
        return arr[3] == 1 && arr[2] == 1;
    }

    bool isThree() const {
        return !isFull() && arr[3];
    }

    bool is2Pair() const {
        return !isFull() && arr[2] == 2;
    }

    bool isPair() const {
        return !is2Pair() && arr[2] == 1;
    }

    bool operator<(const Hand& h) const {
        if (!isFive() && h.isFive())    return true;
        if (isFive() && !h.isFive())    return false;

        if (!isFour() && h.isFour())    return true;
        if (isFour() && !h.isFour())    return false;

        if (!isFull() && h.isFull())    return true;
        if (isFull() && !h.isFull())    return false;

        if (!isThree() && h.isThree())  return true;
        if (isThree() && !h.isThree())  return false;

        if (!is2Pair() && h.is2Pair())  return true;
        if (is2Pair() && !h.is2Pair())  return false;

        if (!isPair() && h.isPair())  return true;
        if (isPair() && !h.isPair())  return false;

        for (int i = 0; i < s.size(); i ++) {
            if (s[i] < h.s[i])  return true;
            if (s[i] > h.s[i])  return false;
        }

        return true;
    }
};
vector<Hand> hands;

void readInput() {
    string line, word;
    string bid;

    while (getline(cin, line)) {
        stringstream stream(line);
        stream >> word >> bid;
        hands.pb(Hand(word, stoi(bid)));
    }
}

int solve() {
    sort(hands.begin(), hands.end());

    ll ret = 0;
    for (int i = 0; i < hands.size(); i ++) {
        ret += hands[i].bid * (i + 1LL);
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
