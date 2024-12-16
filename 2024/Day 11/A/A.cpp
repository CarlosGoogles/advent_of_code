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
typedef pair<ll, ll> ii;
typedef pair<int, string> is;
typedef vector<ll> vi;
typedef vector<is> vis;
typedef unordered_map<string, unordered_set<string>> foo;

#define MAXN    100005
#define MAXK    1000000009
#define MOD     1000000007

int countDigits(ll num) {
    int d = 0;
    while (num) {
        d ++;
        num /= 10;
    }

    return d;
}

void printVec(vi v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

ii splitNum(ll num, int d) {
    ii ret;
    FOR (k, 0, 2) {
        for (ll i = 0, ten = 1; i < d/2; i ++, ten *= 10, num /= 10) {
            ret.first += ten * (num % 10); 
        }
        swap(ret.first, ret.second);
    }
    swap(ret.first, ret.second);

    return ret;
}

vi blink(const vi& nums) {
    vi ret;
    for (ll num : nums) {
        int d = countDigits(num);

        if (num == 0) {
            ret.pb(1);
        }
        else if ((d % 2) == 0) {
            ii num2 = splitNum(num, d);
            ret.pb(num2.first);
            ret.pb(num2.second);
        }
        else {
            ret.pb(num * 2024LL);
        }
    }

    return ret;
}

ll solve(vi& nums) {
    ll ret = 0;
    
    FOR (k, 0, 25) {
        nums = blink(nums);
        // printVec(nums);
    }

    return nums.size();
}

int main() { _
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    
    vi nums;
    string line;
    while (getline(cin, line)) {
        stringstream scin(line);
        ll num;
        while (scin >> num) {
            nums.pb(num);
        }
    }

    cout << solve(nums) << endl;

    return 0;
}
