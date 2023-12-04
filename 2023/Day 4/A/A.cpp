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

int main() { _
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    string card, word;
    long long ans = 0;
    while (getline(cin, card)) {
        ll points = 0;
        stringstream ss(card);
        ss >> word; // Card
        ss >> word; // #:

        unordered_set<ll> nums;
        while (ss >> word && word != "|") {
            ll num = stol(word);
            nums.insert(num);
        }

        while (ss >> word && word != "|") {
            ll num = stol(word);
            if (nums.count(num) != 0) {
                if (points == 0) {
                    points ++;
                }
                else {
                    points *= 2;
                }
            }
        }

        ans += points;
    }

    cout << ans;

    return 0;
}
